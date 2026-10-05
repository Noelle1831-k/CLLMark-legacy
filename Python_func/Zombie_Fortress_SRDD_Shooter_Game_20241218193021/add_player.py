def add_player(self, player):
        '''
        Add a new player to the multiplayer game if the maximum number of players has not been reached.
        '''
        if len(self.players) < self.max_players:
            self.players.append(player)
            self.scores[player] = 0  # Initialize the player's score to 0
        else:
            print("Maximum number of players reached. Cannot add more players.")