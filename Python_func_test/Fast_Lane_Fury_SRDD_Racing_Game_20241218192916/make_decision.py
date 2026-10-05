def make_decision(self, car):
        if car.speed < 10:
            car.accelerate()
        else:
            car.brake()