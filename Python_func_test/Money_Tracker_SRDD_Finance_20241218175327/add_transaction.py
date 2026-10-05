def add_transaction(self, amount, description, date):
        transaction = Transaction(amount, description, self.name, date)
        self.transactions.append(transaction)