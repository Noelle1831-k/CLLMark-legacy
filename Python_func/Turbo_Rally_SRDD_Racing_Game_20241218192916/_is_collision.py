def _is_collision(self, vehicle, obstacle):
        # Improved collision detection logic using bounding circles
        vehicle_position = (vehicle.x, vehicle.y)
        obstacle_position = obstacle
        vehicle_size = 1  # Example size, adjust as needed
        obstacle_size = 1  # Example size, adjust as needed
        # Calculate the distance between the vehicle and the obstacle
        distance = ((vehicle_position[0] - obstacle_position[0]) ** 2 + (vehicle_position[1] - obstacle_position[1]) ** 2) ** 0.5
        return distance < (vehicle_size + obstacle_size)