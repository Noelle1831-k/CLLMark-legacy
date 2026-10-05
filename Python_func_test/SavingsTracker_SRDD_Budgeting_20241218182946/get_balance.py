def get_balance(self):
        total_income = sum([transaction.amount for transaction in self.income])
        total_expenses = sum([transaction.amount for transaction in self.expenses])
        return total_income - total_expenses