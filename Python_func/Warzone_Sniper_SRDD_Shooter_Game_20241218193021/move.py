def move(self):
        # Random movement for targets
        self.position = (self.position[0] + random.randint(-5, 5), self.position[1] + random.randint(-5, 5))
        print(f"Target is moving to position {self.position}...")