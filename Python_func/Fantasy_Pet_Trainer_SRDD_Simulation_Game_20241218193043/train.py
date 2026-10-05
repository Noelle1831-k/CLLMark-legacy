def train(self):
        self.experience += 10
        if self.experience >= 100:
            self.level_up()