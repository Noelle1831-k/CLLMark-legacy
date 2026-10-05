def analyze_expenses(self):
        self.expense_breakdown = {category: amount for category, amount in self.user.expenses.items()}
        return self.expense_breakdown