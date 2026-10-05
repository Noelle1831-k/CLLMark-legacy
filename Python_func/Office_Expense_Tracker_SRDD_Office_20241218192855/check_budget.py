def check_budget(self, category, spent):
        if category in self.budgets:
            return spent > self.budgets[category]
        return False