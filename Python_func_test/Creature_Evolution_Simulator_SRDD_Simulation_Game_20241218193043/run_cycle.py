def run_cycle(self):
        for creature in self.creatures:
            creature.mutate()
        self.select_survivors()
        self.reproduce_creatures()