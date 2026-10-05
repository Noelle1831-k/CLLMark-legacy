def update(self):
        for vehicle in self.vehicles:
            self.physics_engine.update_position(vehicle)
            self.physics_engine.calculate_collision(vehicle, self.terrain.get_obstacles())