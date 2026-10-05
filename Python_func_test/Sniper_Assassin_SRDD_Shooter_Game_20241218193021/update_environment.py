def update_environment(self):
        print("Updating environment based on player actions...")
        self.player_detected = random.choice([True, False])
        self.challenges = [challenge for challenge in self.challenges if random.choice([True, False])]