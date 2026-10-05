def disconnect_player(self, player_id):
        self.players.remove(player_id)
        del self.connections[player_id]