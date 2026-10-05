def update_score(self, car, track):
        self.score += track.calculate_score(car)