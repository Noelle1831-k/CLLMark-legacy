def update_physics(self, car, track):
        self.calculate_drift(car)
        self.apply_friction(car)
        self.check_collisions(car, track)