def upgrade(self):
        self.level += 1
        self.resource_cost *= 1.5
        print(f"{self.name} upgraded to level {self.level}.")