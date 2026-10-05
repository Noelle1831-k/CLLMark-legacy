def shoot(self):
        print("Shooting...")
        trajectory = self.ballistics.calculate_trajectory()
        wind_effect = self.ballistics.calculate_wind_effect()
        hit_probability = self.calculate_hit_probability(trajectory, wind_effect)
        print(f"Hit Probability: {hit_probability}%")