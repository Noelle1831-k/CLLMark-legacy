def add_expense(self, amount, category):
        if amount < 0:
            print("Expense cannot be negative.")
        else:
            self.expense_entries.append((amount, category))