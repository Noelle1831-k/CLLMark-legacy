def apply_physics(self, delta_time):
        gravity = 9.8
        friction = 0.05
        self.active_car.speed -= friction * gravity * delta_time
        if self.active_car.speed < 0:
            self.active_car.speed = 0