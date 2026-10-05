def apply_physics(self, vehicle):
        self.calculate_gravity(vehicle)
        vehicle.velocity[0] = vehicle.velocity[0] + vehicle.acceleration[0]
        vehicle.velocity[1] = vehicle.velocity[1] + vehicle.acceleration[1]
        vehicle.position[0] = vehicle.position[0] + vehicle.velocity[0]
        vehicle.position[1] = vehicle.position[1] + vehicle.velocity[1]