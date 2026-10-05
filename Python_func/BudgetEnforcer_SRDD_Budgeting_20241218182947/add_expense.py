def add_expense(self, amount, category, date):
        expense = Expense(amount, category, date)
        self.expenses.append(expense)