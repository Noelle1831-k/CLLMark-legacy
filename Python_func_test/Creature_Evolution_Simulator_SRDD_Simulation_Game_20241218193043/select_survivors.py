def select_survivors(self):
        survivors = [creature for creature in self.creatures if creature.is_survivor(self.environment)]
        self.creatures = survivors