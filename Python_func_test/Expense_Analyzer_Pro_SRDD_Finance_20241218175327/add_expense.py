def add_expense(self, category, amount):
        if category not in self.expenses:
            self.expenses[category] = list()
        self.expenses[category].append(amount)