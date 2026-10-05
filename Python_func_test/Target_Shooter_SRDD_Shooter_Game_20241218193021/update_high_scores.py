def update_high_scores(self, score):
        self.high_scores.append(score)
        self.high_scores = sorted(self.high_scores, reverse=True)[:5]