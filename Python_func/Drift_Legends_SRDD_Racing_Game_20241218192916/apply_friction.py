def apply_friction(self, car):
        friction_force = self.friction_coefficient * car.speed
        car.speed -= friction_force
        if car.speed < 0:
            car.speed = 0