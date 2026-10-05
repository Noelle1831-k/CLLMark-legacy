def check_high_score(self):
        '''
        Checks and updates the high score if the current score exceeds it.
        '''
        if self.score > self.high_score:
            self.high_score = self.score