def update(self):
        movement = self.physics_engine.calculate_movement(self.vehicle, self.track)
        self.vehicle.update_position(movement)