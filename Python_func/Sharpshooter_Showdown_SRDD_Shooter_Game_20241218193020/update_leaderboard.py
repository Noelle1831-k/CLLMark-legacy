def update_leaderboard(self, player):
        self.scores.append(player.score)
        self.scores.sort(reverse=True)
        self.scores = self.scores[:10]