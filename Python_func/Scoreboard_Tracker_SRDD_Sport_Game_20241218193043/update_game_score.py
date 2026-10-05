def update_game_score(self, game_name, score):
        if game_name in self.scores:
            self.scores[game_name] = score