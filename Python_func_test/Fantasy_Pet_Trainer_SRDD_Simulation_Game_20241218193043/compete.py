def compete(self):
        self.experience += 20
        if self.experience >= 100:
            self.level_up()