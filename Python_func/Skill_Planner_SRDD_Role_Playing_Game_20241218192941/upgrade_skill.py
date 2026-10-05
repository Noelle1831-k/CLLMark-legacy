def upgrade_skill(self):
        if self.level < self.max_level:
            self.level += 1
        else:
            print(f"{self.name} is already at max level.")