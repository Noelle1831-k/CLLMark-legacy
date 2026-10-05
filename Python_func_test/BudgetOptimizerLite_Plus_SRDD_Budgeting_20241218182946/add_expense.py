def add_expense(self, category, amount):
        expense = Expense(category, amount)
        self.expenses.append(expense)