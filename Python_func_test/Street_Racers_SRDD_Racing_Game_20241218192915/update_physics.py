def update_physics(self, car, track):
        car.update_position()
        self.check_collisions(car, track)