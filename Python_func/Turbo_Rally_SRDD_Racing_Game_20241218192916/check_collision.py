def check_collision(self, vehicle):
        # Check for collisions with obstacles
        for obstacle in self.obstacles:
            if self._is_collision(vehicle, obstacle):
                vehicle.brake()