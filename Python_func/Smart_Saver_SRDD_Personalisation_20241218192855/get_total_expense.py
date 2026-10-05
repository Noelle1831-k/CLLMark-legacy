def get_total_expense(self):
        return sum(expense['amount'] for expense in self.expenses)