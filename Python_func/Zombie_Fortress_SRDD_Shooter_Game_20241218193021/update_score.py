def update_score(self, player, points):
        '''
        Update the score of a specific player.
        '''
        if player in self.scores:
            self.scores[player] += points
        else:
            print("Player not found in the game.")