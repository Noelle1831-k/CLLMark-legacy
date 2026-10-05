def brake(self):
        if self.speed > 0:
            self.speed -= self.acceleration