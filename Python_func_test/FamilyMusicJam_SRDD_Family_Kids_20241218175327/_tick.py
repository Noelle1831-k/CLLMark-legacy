def _tick(self):
        """Simulate metronome ticking at the specified BPM."""
        while self.is_running:
            print("Tick")
            time.sleep(60 / self.bpm)