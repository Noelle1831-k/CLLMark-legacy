def update(self, player):
        '''
        Update the leaderboard with a player's score.
        '''
        self.scores[player.name] = player.score
        self.display()