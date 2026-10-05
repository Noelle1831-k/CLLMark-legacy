def get_challenge_by_id(self, challenge_id):
        for challenge in self.challenges:
            if challenge.id == challenge_id:
                return challenge
        return None