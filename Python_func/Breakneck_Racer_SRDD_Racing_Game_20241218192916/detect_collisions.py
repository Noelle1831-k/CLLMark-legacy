def detect_collisions(self):
        for obstacle in self.obstacles:
            if self.active_car.is_colliding_with(obstacle):
                print("Collision detected!")