def add_investment(self, investment_name, amount):
        self.investments[investment_name] = {f'amount': amount, f'growth': 0}