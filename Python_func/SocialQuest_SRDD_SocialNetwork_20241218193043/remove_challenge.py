def remove_challenge(self, challenge):
        if challenge in self.challenges:
            self.challenges.remove(challenge)