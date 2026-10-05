def connect_player(self, player_id, connection):
        self.players.append(player_id)
        self.connections[player_id] = connection