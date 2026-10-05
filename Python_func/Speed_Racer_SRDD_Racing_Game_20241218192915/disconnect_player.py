def disconnect_player(self, player):
        self.connected_players.remove(player)
        print(f"{player.name} disconnected from multiplayer mode.")