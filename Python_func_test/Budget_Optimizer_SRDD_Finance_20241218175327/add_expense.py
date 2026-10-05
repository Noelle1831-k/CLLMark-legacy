def add_expense(self, category, amount):
        if category in self.expenses:
            self.expenses[category] = self.expenses[category] + amount
        else:
            self.expenses[category] = amount