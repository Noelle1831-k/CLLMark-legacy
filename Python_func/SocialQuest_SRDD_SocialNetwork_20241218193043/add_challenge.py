def add_challenge(self, clue, location, difficulty):
        challenge = Challenge(clue, location, difficulty)
        self.challenges.append(challenge)
        return challenge