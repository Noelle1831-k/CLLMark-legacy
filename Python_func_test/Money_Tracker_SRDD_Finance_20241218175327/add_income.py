def add_income(self, amount, description, date):
        transaction = Transaction(amount, description, "Income", date)
        self.income.append(transaction)