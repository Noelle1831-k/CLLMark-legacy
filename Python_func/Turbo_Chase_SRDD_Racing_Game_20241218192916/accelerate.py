def accelerate(self):
        if self.speed < self.max_speed:
            self.speed += self.acceleration
            print(f"Accelerating. Current speed: {self.speed}")
        else:
            print("Maximum speed reached!")