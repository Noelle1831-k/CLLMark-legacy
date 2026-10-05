def calculate_budget(self):
        total_expenses = sum(self.expenses.values())
        return self.income - total_expenses