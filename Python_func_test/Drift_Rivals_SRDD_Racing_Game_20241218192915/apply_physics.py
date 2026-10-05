def apply_physics(self, car):
        car.position = (car.position[0] + car.speed, car.position[1])