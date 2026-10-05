def add_expense(self, expense, category):
        try:
            self.expenses.append({"amount": float(expense), "category": category})
        except ValueError:
            raise ValueError("Invalid expense amount. Please enter a numeric value.")