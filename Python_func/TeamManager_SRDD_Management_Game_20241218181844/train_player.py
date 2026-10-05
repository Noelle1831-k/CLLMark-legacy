def train_player(self, player_name):
        for p in self.players:
            if p.name == player_name:
                p.update_stats()