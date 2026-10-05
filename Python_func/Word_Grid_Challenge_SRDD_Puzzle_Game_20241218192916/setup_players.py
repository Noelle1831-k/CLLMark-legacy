def setup_players(self):
        '''
        Setup players for the game.
        '''
        num_players = int(input("Enter number of players: "))
        for _ in range(num_players):
            name = input("Enter player name: ")
            self.players.append(Player(name))