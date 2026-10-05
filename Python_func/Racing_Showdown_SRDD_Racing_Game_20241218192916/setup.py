def setup(self):
        # Setup race track
        for i, obstacle in enumerate(self.obstacles):
            obstacle.position = (i * 100, 200)  # Example positions
        for i, powerup in enumerate(self.powerups):
            powerup.position = (i * 150, 300)  # Example positions