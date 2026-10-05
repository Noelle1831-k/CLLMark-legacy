def update_accuracy(self):
        if self.shots_fired > 0:
            self.accuracy = (self.shots_hit / self.shots_fired) * 100