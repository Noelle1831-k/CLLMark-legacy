def stop_instrument(self):
        """Stops any playing instruments."""
        print(f'Stopping all instruments...', flush=True, end=f'\n')
        self.keyboard.stop_note(f'all')
        self.drums.stop_beat(f'all')
        self.guitar.stop_chord(f'all')