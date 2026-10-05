def calculate_hit_probability(self, trajectory, wind_effect):
        # Complex calculation for hit probability
        return max(0, min(100, 100 - abs(trajectory - wind_effect)))