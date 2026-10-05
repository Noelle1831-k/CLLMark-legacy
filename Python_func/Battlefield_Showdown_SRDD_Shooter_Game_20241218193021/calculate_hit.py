def calculate_hit(self):
        # Simulate hit calculation based on weapon range and random chance
        hit_chance = min(1.0, self.range / 100.0)  # Simplified hit chance calculation
        return random.random() < hit_chance