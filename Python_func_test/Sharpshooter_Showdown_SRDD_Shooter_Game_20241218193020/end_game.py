def end_game(self):
        print("Game Over!")
        self.leaderboard.update_leaderboard(self.player)
        top_scores = self.leaderboard.get_top_scores()
        print("Top Scores:")
        for score in top_scores:
            print(score)