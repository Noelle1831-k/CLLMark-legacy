"""Progress bar, ETA and the per-unit live log of a running experiment."""

import json
import sys
import time
from collections import Counter, deque
from pathlib import Path

LOG_NAME = "progress.log"
WINDOW_SECONDS = 60


def format_duration(seconds):
    if seconds is None or seconds != seconds or seconds == float("inf"):
        return "--:--"
    seconds = int(seconds)
    hours, rest = divmod(seconds, 3600)
    minutes, seconds = divmod(rest, 60)
    return f"{hours}:{minutes:02d}:{seconds:02d}" if hours else f"{minutes:02d}:{seconds:02d}"


def render_bar(done, total, width=30):
    fraction = min(1.0, done / total) if total else 1.0
    filled = int(width * fraction)
    return f"[{'#' * filled}{'-' * (width - filled)}] {done}/{total} {fraction * 100:5.1f}%"


class ProgressTracker:
    """Counts finished units and estimates the rate from the last minute, so cache warm-up does not skew the ETA."""

    def __init__(self, total, done=0, clock=time.monotonic):
        self.total, self.done, self.clock = total, done, clock
        self.start = clock()
        self.start_done = done
        self.recent = deque([(self.start, done)])
        self.statuses = Counter()
        self.cohorts = Counter()

    def update(self, row):
        self.done += 1
        self.statuses[row.get("status", "?")] += 1
        self.cohorts[row.get("cohort", "?")] += 1
        now = self.clock()
        self.recent.append((now, self.done))
        while len(self.recent) > 2 and now - self.recent[0][0] > WINDOW_SECONDS:
            self.recent.popleft()

    @property
    def elapsed(self):
        return self.clock() - self.start

    @property
    def rate(self):
        (first_time, first_done), (last_time, last_done) = self.recent[0], self.recent[-1]
        span = last_time - first_time
        return (last_done - first_done) / span if span > 0 else 0.0

    @property
    def eta(self):
        rate = self.rate
        return (self.total - self.done) / rate if rate > 0 else None

    def line(self, last=""):
        problems = self.total and sum(count for status, count in self.statuses.items() if status != "ok")
        text = (
            f"{render_bar(self.done, self.total)} {self.rate:5.1f} unit/s "
            f"elapsed {format_duration(self.elapsed)} eta {format_duration(self.eta)} not-ok={problems}"
        )
        return f"{text} | {last}" if last else text

    def state(self):
        eta = self.eta
        return {
            "total_units": self.total,
            "completed_units": self.done,
            "units_per_second": round(self.rate, 3),
            "elapsed_seconds": round(self.elapsed, 1),
            "eta_seconds": None if eta is None else round(eta, 1),
            "status_counts": dict(self.statuses),
            "cohort_counts": dict(self.cohorts),
        }


class LiveLog:
    """One line per finished unit, flushed at once so `progress --follow` and `tail -f` see it immediately."""

    def __init__(self, path, tracker, stream=None):
        self.file = Path(path).open("a", encoding="utf-8", buffering=1)  # noqa: SIM115 - closed by close()
        self.tracker, self.stream = tracker, stream or sys.stdout
        self.interactive = self.stream.isatty()
        self.last_print = 0.0

    def record(self, row, part=""):
        self.tracker.update(row)
        extra = f" {row['elapsed_ms'] / 1000:.2f}s" if isinstance(row.get("elapsed_ms"), (int, float)) else ""
        stamp = time.strftime("%H:%M:%S")
        self.file.write(
            f"{stamp} {self.tracker.done}/{self.tracker.total} {row.get('status', '?')} {row['id']}{extra}\n"
        )
        if row.get("status") != "ok" and not self.interactive:
            print(f"{stamp} {row.get('status')} {row['id']}", file=self.stream, flush=True)

    def show(self, force=False):
        now = time.monotonic()
        if not force and now - self.last_print < (0.5 if self.interactive else 20):
            return
        self.last_print = now
        if self.interactive:
            print("\r\x1b[2K" + self.tracker.line(), end="\n" if force else "", file=self.stream, flush=True)
        else:
            print("Progress " + self.tracker.line(), file=self.stream, flush=True)

    def close(self):
        self.show(force=True)
        self.file.close()


RAM_RESULTS = (Path("/Volumes/CLLMarkRAM/benchmark-results"), Path("/dev/shm/cllmark-ram/benchmark-results"))


def latest_run(output_root):
    """The newest run directory, on disk or on the RAM disk of `make benchmark-ram`; names start with a UTC timestamp."""
    runs = [
        run
        for root in (Path(output_root), *RAM_RESULTS)
        if root.is_dir()
        for run in root.iterdir()
        if (run / "state.json").exists()
    ]
    return max(runs, key=lambda run: run.name, default=None)


def describe(run_dir, tail=10):
    """Text view of a run directory: phase, bar, ETA, per-cohort counts and the most recent unit lines."""
    run_dir = Path(run_dir)
    state = json.loads((run_dir / "state.json").read_text())
    status = state.get("status")
    phase = f" [{state['phase']}]" if state.get("phase") else ""
    lines = [f"{run_dir.name}: {status}{phase} (updated {state.get('updated_at', '?')})"]
    if status == "freezing":
        lines.append("freezing inputs " + render_bar(state.get("copied_inputs", 0), state.get("expected_inputs", 0)))
    elif "total_units" in state:
        lines.append(
            f"{render_bar(state['completed_units'], state['total_units'])} {state.get('units_per_second', 0):.1f} unit/s "
            f"elapsed {format_duration(state.get('elapsed_seconds'))} eta {format_duration(state.get('eta_seconds'))}"
        )
        lines.append("status: " + ", ".join(f"{k}={v}" for k, v in sorted(state.get("status_counts", {}).items())))
        lines.append(
            "this session by cohort: "
            + ", ".join(f"{k}={v}" for k, v in sorted(state.get("cohort_counts", {}).items()))
        )
    log = run_dir / LOG_NAME
    if log.exists() and tail:
        lines += ["", f"last {tail} units:", *log.read_text(encoding="utf-8").splitlines()[-tail:]]
    return "\n".join(lines)


def follow(run_dir, interval=2.0, tail=10, stream=None):
    stream = stream or sys.stdout
    while True:
        print("\x1b[2J\x1b[H" if stream.isatty() else "", describe(run_dir, tail), sep="", file=stream, flush=True)
        if json.loads((Path(run_dir) / "state.json").read_text()).get("status") in {
            "complete",
            "failed",
            "stale",
            "interrupted",
        }:
            return
        time.sleep(interval)
