def update_expense(self, category, old_amount, new_amount):
        if category in self.expenses and old_amount in self.expenses[category]:
            index = self.expenses[category].index(old_amount)
            self.expenses[category][index] = new_amount