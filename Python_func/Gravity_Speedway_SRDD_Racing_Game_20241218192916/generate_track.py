def generate_track(self):
        # Generate obstacles with random positions
        self.obstacles = [obstacle.Obstacle(self.track_width, self.track_height) for _ in range(10)]