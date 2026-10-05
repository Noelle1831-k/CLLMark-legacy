def add_investment(self, investment_name, amount):
        self.investments[investment_name] = {"amount": amount, "growth": 0}