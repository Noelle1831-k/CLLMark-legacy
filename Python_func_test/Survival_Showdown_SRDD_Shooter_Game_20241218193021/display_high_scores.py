def display_high_scores(self):
        # Implement high score display logic
        print("High Scores:")
        for score in sorted(self.high_scores, reverse=True):
            print(score)