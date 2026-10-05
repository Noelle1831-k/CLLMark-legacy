def generate_challenge(self):
        '''
        Randomly generates a new challenge for the user.
        '''
        challenges = ["Complete 3 push-ups", "Run for 5 minutes", "Do 10 squats", "Perform 20 sit-ups"]
        self.challenge = random.choice(challenges)
        print(f"Your challenge: {self.challenge}")
        return True