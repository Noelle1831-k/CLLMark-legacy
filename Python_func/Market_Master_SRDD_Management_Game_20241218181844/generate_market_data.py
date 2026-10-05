def generate_market_data(self):
        for stock in self.stocks:
            self.stocks[stock] *= random.uniform(0.95, 1.05)  # Random fluctuation