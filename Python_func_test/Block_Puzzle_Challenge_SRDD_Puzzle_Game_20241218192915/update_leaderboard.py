def update_leaderboard(self, score):
        """
        Updates the leaderboard with a new score.
        """
        self.scores.append(score)
        self.scores.sort(reverse=True)
        print("Leaderboard updated.")