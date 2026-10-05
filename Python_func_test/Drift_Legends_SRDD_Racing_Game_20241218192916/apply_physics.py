def apply_physics(self, car):
        self.apply_friction(car)
        self.apply_air_resistance(car)
        self.apply_gravity(car)