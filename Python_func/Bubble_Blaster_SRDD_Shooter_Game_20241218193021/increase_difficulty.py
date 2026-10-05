def increase_difficulty(self, score_manager):
        if score_manager.score >= self.threshold:
            self.level += 1
            self.threshold *= 2