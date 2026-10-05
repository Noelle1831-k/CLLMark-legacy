def get_total_expenses(self):
        return sum(expense['amount'] for expense in self.expenses)