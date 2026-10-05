def update_position(self, vehicle):
        vehicle.position = (vehicle.position[0] + vehicle.speed * math.cos(vehicle.direction),
                            vehicle.position[1] + vehicle.speed * math.sin(vehicle.direction))