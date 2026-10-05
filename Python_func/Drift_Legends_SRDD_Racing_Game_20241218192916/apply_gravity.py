def apply_gravity(self, car):
        car.position[1] -= self.gravity * 0.01
        if car.position[1] < 0:
            car.position[1] = 0