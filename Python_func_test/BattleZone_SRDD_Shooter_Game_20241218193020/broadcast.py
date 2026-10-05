def broadcast(self, message):
        for player_id in self.players:
            connection = self.connections[player_id]
            connection.send(message)