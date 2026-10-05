def calculate_collision(self, vehicle, obstacles):
        for obstacle in obstacles:
            if obstacle.check_collision(vehicle):
                vehicle.speed = 0