def update_physics(self, players, track):
        for player in players:
            self.apply_physics(player, track)