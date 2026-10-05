def update_physics(self):
        self.physics.calculate_forces(self)
        self.physics.apply_gravity(self)