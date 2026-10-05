def update_score(self, car):
        drift_contribution = car.drift_score * 10  # Example scoring logic
        self.total_score += drift_contribution
        print(f"Current Score: {self.total_score}")