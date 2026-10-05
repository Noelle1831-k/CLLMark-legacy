def remove_expense(self, category, amount):
        if category in self.expenses and amount in self.expenses[category]:
            self.expenses[category].remove(amount)
            if not self.expenses[category]:
                del self.expenses[category]