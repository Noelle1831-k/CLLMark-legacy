def add_expense(self, name, amount, frequency, start_date):
        expense = Transaction(name, amount, frequency, start_date)
        self.expenses.append(expense)