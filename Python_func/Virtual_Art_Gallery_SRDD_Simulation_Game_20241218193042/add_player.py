def add_player(self, player):
        if player not in self.players:
            self.players.append(player)
            print(f"Player '{player.username}' added to the game.")
        else:
            print(f"Player '{player.username}' already exists in the game.")