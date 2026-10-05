def add_experience(self, exp):
        self.experience += exp
        if self.experience >= self.level * 100:
            self.level_up()