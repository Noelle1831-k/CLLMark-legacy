def get_balance(self):
        return sum(t.amount for t in self.transactions)