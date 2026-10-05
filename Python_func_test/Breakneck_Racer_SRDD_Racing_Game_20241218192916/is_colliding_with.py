def is_colliding_with(self, obstacle):
        car_width, car_height = 50, 100  # Example dimensions
        obstacle_width, obstacle_height = 10, 10  # Example dimensions
        return (abs(self.position[0] - obstacle['x']) < (car_width + obstacle_width) / 2 and
                abs(self.position[1] - obstacle['y']) < (car_height + obstacle_height) / 2)