def stop_instrument(self):
        """Stops any playing instruments."""
        print("Stopping all instruments...")
        self.keyboard.stop_note("all")
        self.drums.stop_beat("all")
        self.guitar.stop_chord("all")