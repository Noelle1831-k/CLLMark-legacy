def stop_track(self):
        """Simulate stopping the track."""
        if self.current_track:
            print(f"Stopping track: {self.current_track}")
            self.current_track = None
        else:
            print("No track to stop.")