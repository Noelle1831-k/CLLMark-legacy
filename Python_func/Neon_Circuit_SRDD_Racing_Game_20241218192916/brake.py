def brake(self):
        self.speed = max(0, self.speed - 1)