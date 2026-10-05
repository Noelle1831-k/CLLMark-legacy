def add_game(self, game_name):
        if game_name not in self.scores:
            self.scores[game_name] = (0, 0)