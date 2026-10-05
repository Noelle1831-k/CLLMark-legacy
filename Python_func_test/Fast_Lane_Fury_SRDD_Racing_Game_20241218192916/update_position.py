def update_position(self):
        self.position += self.speed
        self.steer(random.uniform(-0.1, 0.1))