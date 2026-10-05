def apply_drag(self, car):
        drag_force = self.drag_coefficient * car.speed ** 2 / car.weight
        car.speed -= drag_force
        if car.speed < 0:
            car.speed = 0