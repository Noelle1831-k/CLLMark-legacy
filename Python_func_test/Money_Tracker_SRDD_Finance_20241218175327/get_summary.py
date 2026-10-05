def get_summary(self):
        total_income = sum(t.amount for t in self.income)
        total_expenses = sum(t.amount for t in self.expenses)
        return f'Total Income: ${total_income}, Total Expenses: ${total_expenses}'