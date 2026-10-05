def decelerate(self):
        self.speed = max(0, self.speed - self.acceleration)