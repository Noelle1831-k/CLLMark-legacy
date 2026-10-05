def remove_player(self, player):
        if player in self.players:
            self.players.remove(player)
            print(f"Player '{player.username}' removed from the game.")
        else:
            print(f"Player '{player.username}' not found in the game.")