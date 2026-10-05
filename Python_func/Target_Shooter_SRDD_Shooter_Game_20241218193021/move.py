def move(self):
        direction = random.choice([-1, 1])
        self.position = (self.position[0] + self.speed * direction, self.position[1] + self.speed * direction)
        if self.position[0] > 800 or self.position[0] < 0:
            self.position = (random.randint(0, 800), self.position[1])
        if self.position[1] > 600 or self.position[1] < 0:
            self.position = (self.position[0], random.randint(0, 600))