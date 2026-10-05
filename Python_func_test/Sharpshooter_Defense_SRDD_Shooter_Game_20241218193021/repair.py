def repair(self, amount):
        self.health += amount
        print(f"Base repaired by {amount}, health is now {self.health}")