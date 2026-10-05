def delete_challenge(self, challenge_id):
        if challenge_id in self.challenges:
            del self.challenges[challenge_id]
            print(f"Challenge with ID '{challenge_id}' deleted from database.")