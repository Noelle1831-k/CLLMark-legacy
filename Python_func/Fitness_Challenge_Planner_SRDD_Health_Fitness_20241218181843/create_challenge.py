def create_challenge(self, challenge):
        self.challenges.append(challenge)
        print(f"Challenge '{challenge.name}' created for user '{self.username}'.")