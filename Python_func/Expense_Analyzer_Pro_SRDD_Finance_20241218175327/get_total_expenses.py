def get_total_expenses(self):
        return sum(sum(amounts) for amounts in self.expenses.values())