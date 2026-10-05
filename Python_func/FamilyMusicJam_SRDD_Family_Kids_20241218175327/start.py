def start(self):
        """Starts the metronome with the current beats per minute (BPM)."""
        self.is_running = True
        print(f"Metronome started at {self.bpm} BPM.")
        self._tick()