def update_position(self):
        # Update vehicle position based on speed and direction
        self.position[0] += self.speed * self.direction
        self.position[1] += self.speed