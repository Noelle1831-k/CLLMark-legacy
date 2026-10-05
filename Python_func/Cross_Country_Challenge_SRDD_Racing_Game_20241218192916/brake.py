def brake(self, amount):
        self.speed = max(0, self.speed - amount)