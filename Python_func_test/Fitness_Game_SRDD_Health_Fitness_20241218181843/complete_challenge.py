def complete_challenge(self):
        '''
        Completes the challenge and rewards points to the user.
        '''
        print(f"Challenge Completed: {self.challenge}")
        self.user.gain_points(self.challenge_points)
        print(f"Earned {self.challenge_points} extra points!")