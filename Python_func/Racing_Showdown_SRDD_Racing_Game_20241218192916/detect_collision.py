def detect_collision(self, vehicle):
        '''
        Detect if a vehicle has collided with the obstacle.
        :param vehicle: The vehicle object to check collision with.
        :return: True if collision is detected, False otherwise.
        '''
        vehicle_x, vehicle_y = vehicle.position
        obstacle_x, obstacle_y = self.position
        obstacle_width, obstacle_height = self.size
        # Check if vehicle's position overlaps with the obstacle's position
        if (obstacle_x < vehicle_x < obstacle_x + obstacle_width) and \
           (obstacle_y < vehicle_y < obstacle_y + obstacle_height):
            return True
        return False