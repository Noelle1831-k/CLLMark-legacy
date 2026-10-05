def determine_winner(self):
        return max(self.players, key=lambda player: player.health)