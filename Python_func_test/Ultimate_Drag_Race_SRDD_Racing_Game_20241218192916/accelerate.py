def accelerate(self):
        if (self.speed <= self.max_speed and self.speed != self.max_speed):
            self.speed += self.acceleration * (1 - self.speed / self.max_speed)