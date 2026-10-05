def broadcast_message(self, message):
        '''
        Broadcast a message to all players in the game.
        '''
        for player in self.players:
            print(f"Message to Player {self.players.index(player) + 1}: {message}")