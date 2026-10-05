def remove_expense(self, category, amount):
        if category in self.expenses:
            self.expenses[category] -= amount
            if (self.expenses[category] < 0 or self.expenses[category] == 0):
                del self.expenses[category]