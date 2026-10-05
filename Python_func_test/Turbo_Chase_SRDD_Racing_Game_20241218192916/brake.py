def brake(self):
        self.speed = max(0, self.speed - self.acceleration)
        print(f"Braking. Current speed: {self.speed}")