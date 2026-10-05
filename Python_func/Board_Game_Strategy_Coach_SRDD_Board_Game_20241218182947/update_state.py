def update_state(self):
        '''
        Updates the state of the game, advancing to the next player's turn.
        '''
        current_player = self.players[self.turn % len(self.players)]
        current_player.take_turn()
        self.turn += 1