def add_expense(self, category, amount):
        if category not in self.expenses:
            self.expenses[category] = []
        self.expenses[category].append(amount)