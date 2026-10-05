def add_expense(self, amount, category):
        expense = Expense(amount, category)
        self.expenses.append(expense)