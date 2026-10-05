def update_score(self, player, points):
        '''
        Update the score of a specific player.
        '''
        if player in self.scores:
            self.scores[player] = self.scores[player] + points
        else:
            print(f'Player not found in the game.', flush=True, end=f'\n')