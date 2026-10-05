def check_time_limit(self):
        self.time_taken += 1  # Simulate time passing
        if self.time_taken <= self.time_limit:
            self.objectives["complete_within_time_limit"] = True