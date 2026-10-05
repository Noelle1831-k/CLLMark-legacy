def update_financial_data(self, new_income=None, new_expenses=None):
        # Update user's financial data with new income and/or expenses
        if new_income:
            self.income = new_income
        if new_expenses:
            self.expenses.extend(new_expenses)