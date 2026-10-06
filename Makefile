BENCH_PYTHON ?= .venv-benchmark/bin/python
RUFF ?= .venv-benchmark/bin/ruff

.PHONY: corpus setup-benchmark setup-javascript setup-dev doctor inventory test lint format perf smoke benchmark baseline watch-benchmark code-map

corpus:
	git submodule update --init corpus

setup-benchmark:
	python3 tools/setup_benchmark.py

setup-javascript:
	$(BENCH_PYTHON) tools/setup_javascript.py

setup-dev:
	if command -v uv >/dev/null; then uv pip install --python $(BENCH_PYTHON) -r benchmarks/dev-requirements.lock; \
	else $(BENCH_PYTHON) -m pip install -r benchmarks/dev-requirements.lock; fi

doctor:
	$(BENCH_PYTHON) tools/research_loop.py doctor

inventory:
	$(BENCH_PYTHON) tools/research_loop.py inventory

test:
	$(BENCH_PYTHON) -m unittest discover -s tests -v

lint:
	$(RUFF) check .
	$(RUFF) format --check .

format:
	$(RUFF) check --fix .
	$(RUFF) format .

perf:
	$(BENCH_PYTHON) tools/perf_benchmark.py

smoke: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop --limit 2

benchmark: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop

baseline: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop --initialize-baseline

watch-benchmark:
	$(BENCH_PYTHON) tools/research_loop.py watch

code-map:
	python3 tools/build_code_index.py
