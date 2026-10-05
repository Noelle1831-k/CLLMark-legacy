def get_balance(self):
        return self.income - sum(expense['amount'] for expense in self.expenses)