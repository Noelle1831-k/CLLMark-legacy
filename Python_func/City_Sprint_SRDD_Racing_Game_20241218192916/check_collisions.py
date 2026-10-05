def check_collisions(self, car, obstacles):
        car_rect = (*car.position, 20, 10)
        for obstacle in obstacles:
            if self.rects_collide(car_rect, obstacle):
                self.handle_collision(car)