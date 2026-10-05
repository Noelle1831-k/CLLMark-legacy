def make_decision(self, challenge):
        '''
        Makes a strategic decision based on the challenge's difficulty and current colony status.
        '''
        print(f"Evaluating challenge with difficulty: {challenge.difficulty}")
        decision = self.evaluate_risks(challenge)
        print(f"Decision made: {decision}")
        challenge.resolve_challenge(decision)