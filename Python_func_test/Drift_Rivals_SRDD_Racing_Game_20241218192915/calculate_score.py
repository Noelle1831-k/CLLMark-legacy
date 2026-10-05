def calculate_score(self, car):
        score = 0
        for zone in self.drift_zones:
            if self.is_in_drift_zone(car.position, zone):
                score += 10
        return score