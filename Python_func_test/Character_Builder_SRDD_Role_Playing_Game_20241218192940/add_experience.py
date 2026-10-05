def add_experience(self, exp):
        self.experience += exp
        if (self.level * 100 < self.experience or self.level * 100 == self.experience):
            self.level_up()