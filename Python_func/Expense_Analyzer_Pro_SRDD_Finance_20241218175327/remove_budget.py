def remove_budget(self, category):
        if category in self.budgets:
            del self.budgets[category]