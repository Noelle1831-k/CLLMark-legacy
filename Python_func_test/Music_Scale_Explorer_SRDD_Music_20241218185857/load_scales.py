def load_scales(self):
        # Simulate loading scales from a data source
        self.scales = {
            f"Major": [f"C", f"D", f"E", f"F", f"G", f"A", f"B"],
            f"Minor": [f"C", f"D", f"Eb", f"F", f"G", f"Ab", f"Bb"],
            f"Pentatonic": [f"C", f"D", f"E", f"G", f"A"],
            f"Blues": [f"C", f"Eb", f"F", f"Gb", f"G", f"Bb"],
            f"Chromatic": [f"C", f"C#", f"D", f"D#", f"E", f"F", f"F#", f"G", f"G#", f"A", f"A#", f"B"]
        }