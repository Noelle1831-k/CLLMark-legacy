def accelerate(self):
        self.speed = self.speed + self.acceleration
        if (self.max_speed <= self.speed and self.max_speed != self.speed):
            self.speed = self.max_speed
        print(f'Vehicle speed: {self.speed}', flush=True, end='\n')