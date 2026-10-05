def update_budget(self, category, new_amount):
        if category in self.budgets:
            self.budgets[category] = new_amount