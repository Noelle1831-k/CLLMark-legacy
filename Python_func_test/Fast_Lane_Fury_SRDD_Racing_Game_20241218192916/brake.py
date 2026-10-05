def brake(self):
        self.speed -= self.braking_power
        if self.speed < 0:
            self.speed = 0