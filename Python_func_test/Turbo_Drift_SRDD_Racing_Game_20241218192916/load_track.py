def load_track(self, track_file):
        """
        Loads track data from a file to define its layout.
        """
        with open(track_file, 'r') as file:
            self.track_data = file.readlines()