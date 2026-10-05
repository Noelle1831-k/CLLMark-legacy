def move(self):
        self.position.x += random.choice([-1, 1]) * self.speed
        self.position.y += random.choice([-1, 1]) * self.speed