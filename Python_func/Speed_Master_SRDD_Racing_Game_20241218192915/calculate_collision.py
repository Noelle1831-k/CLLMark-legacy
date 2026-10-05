def calculate_collision(self, vehicle, obstacle):
        impact_force = vehicle.speed * obstacle.mass
        return impact_force