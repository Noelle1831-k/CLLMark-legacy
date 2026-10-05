def generate_track(self):
        # Generate a track with random obstacles
        self.obstacles = [(i, i*2) for i in range(10)]