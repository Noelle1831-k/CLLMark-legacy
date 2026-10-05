def categorize_investment(self, investment, category):
        if category in self.portfolios:
            self.portfolios[category].add_to_portfolio(investment)