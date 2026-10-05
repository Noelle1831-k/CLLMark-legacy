def update_evaluation(self, score=None, comments=None):
        if score:
            self.score = score
        if comments:
            self.comments = comments