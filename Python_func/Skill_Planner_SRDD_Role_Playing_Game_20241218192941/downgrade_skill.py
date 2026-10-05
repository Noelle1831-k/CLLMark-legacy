def downgrade_skill(self):
        if self.level > 0:
            self.level -= 1
        else:
            print(f"{self.name} is already at the minimum level.")