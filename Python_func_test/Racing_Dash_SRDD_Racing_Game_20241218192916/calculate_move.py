def calculate_move(self):
        # Simple AI logic to adjust speed and direction
        self.speed = min(self.speed + self.acceleration, self.max_speed)
        self.x = self.x + self.speed
        self.y = self.y + self.handling * self.speed