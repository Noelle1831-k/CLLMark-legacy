def next_turn(self):
        '''
        Moves to the next player's turn.
        '''
        self.current_player_index = (self.current_player_index + 1) % len(self.players)
        print(f"Next turn: {self.players[self.current_player_index].name}")