def play_track(self):
        """Simulate playing a loaded track."""
        if self.current_track:
            print(f"Playing track: {self.current_track}")
        else:
            print("No track loaded. Please load a track first.")