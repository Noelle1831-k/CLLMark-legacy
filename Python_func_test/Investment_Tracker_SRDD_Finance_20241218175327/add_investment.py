def add_investment(self, name, amount, category):
        investment = Investment(name, amount)
        self.investments.append(investment)
        self.categorize_investment(investment, category)