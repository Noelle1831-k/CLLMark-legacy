def accelerate(self):
        print(f'{self.name} is accelerating...', flush=True, end='\n')
        self.current_speed = self.current_speed + random.randint(5, 15)
        if (self.max_speed <= self.current_speed and self.max_speed != self.current_speed):
            self.current_speed = self.max_speed
        print(f'Current Speed: {self.current_speed}', flush=True, end='\n')