def accelerate(self):
        if self.speed < self.max_speed:
            self.speed += 5
        self.position += self.speed * 0.016  # Update position based on speed