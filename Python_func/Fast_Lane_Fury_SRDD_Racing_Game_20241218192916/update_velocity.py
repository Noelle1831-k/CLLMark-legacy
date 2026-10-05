def update_velocity(self, car):
        self.apply_gravity(car)
        self.calculate_friction(car)