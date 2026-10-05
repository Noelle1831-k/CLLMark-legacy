def remove_player(self, player):
        '''
        Remove a player from the multiplayer game.
        '''
        if player in self.players:
            self.players.remove(player)
            del self.scores[player]
        else:
            print("Player not found in the game.")