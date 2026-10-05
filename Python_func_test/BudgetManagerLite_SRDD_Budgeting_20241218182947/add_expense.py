def add_expense(self, amount, category):
        amount = validate_amount(amount)  # Validate the amount
        expense = Expense(amount, category)
        self.expenses.append(expense)