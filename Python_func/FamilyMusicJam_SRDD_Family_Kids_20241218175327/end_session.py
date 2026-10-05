def end_session(self):
        """Ends the current music jam session, stopping the metronome and any remaining activities."""
        print("Ending Family Music Jam Session...")
        self.metronome.stop()