def load_players(self):
        for i in range(4):
            self.players.append(player.Player(f"Player {i+1}"))