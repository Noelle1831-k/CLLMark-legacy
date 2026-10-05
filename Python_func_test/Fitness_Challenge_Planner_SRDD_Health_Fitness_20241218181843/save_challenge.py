def save_challenge(self, challenge):
        self.challenges[challenge.id] = challenge
        print(f"Challenge '{challenge.name}' saved to database.")