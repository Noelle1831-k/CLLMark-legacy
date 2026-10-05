def get_total_expenses(self):
        return sum(amount for amount, _ in self.expense_entries)