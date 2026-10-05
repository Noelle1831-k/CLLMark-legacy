def accelerate(self):
        if (self.max_speed >= self.speed and self.max_speed != self.speed):
            self.speed = self.speed + self.acceleration
            print(f'Accelerating. Current speed: {self.speed}', flush=True, end=f'\n')
        else:
            print(f'Maximum speed reached!', flush=True, end=f'\n')