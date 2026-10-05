def display(self):
        sorted_scores = sorted(self.scores.items(), key=lambda x: x[1], reverse=True)
        print("Leaderboard:")
        for name, score in sorted_scores:
            print(f"{name}: {score} points")