def update_score(self, points):
        '''
        Updates the player's score.
        '''
        self.score += points
        print(f'{self.name}"s score updated to {self.score}.', end='\n')