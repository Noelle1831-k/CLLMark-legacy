def add_expense(self, amount, description, date):
        transaction = Transaction(amount, description, "Expense", date)
        self.expenses.append(transaction)