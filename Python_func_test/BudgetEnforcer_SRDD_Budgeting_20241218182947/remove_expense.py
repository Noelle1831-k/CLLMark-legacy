def remove_expense(self, expense):
        if expense in self.expenses:
            self.expenses.remove(expense)