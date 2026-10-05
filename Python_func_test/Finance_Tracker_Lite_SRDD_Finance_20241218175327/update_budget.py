def update_budget(self, amount, category):
        if category in self.spent:
            self.spent[category] += amount