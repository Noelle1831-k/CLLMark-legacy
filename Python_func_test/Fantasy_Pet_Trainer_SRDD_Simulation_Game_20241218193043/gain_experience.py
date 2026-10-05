def gain_experience(self, amount):
        self.experience += amount
        if self.experience >= 100:
            self.level_up()