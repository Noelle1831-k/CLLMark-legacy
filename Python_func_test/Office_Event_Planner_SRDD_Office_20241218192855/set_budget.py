def set_budget(self, budget):
        if self.events:
            self.events[-1].budget = budget