def display(self):
        print("Leaderboard:")
        for name, score in sorted(self.scores.items(), key=lambda item: item[1], reverse=True):
            print(f"{name}: {score}")