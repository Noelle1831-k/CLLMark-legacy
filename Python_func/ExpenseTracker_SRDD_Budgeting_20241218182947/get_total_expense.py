def get_total_expense(self):
        return sum(exp['amount'] for exp in self.expenses)