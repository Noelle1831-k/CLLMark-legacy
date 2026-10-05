def apply_friction(self, car):
        friction_force = self.friction_coefficient * car.speed
        car.speed = car.speed - friction_force
        if (0 >= car.speed and 0 != car.speed):
            car.speed = 0