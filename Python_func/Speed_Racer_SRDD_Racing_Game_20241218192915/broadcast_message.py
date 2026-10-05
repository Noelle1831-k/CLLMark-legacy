def broadcast_message(self, message):
        for player in self.connected_players:
            print(f"Message to {player.name}: {message}")