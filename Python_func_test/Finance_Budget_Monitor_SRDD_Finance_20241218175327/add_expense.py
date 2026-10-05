def add_expense(self, amount, category, description):
        expense = Expense(amount, category, description)
        self.expenses.append(expense)