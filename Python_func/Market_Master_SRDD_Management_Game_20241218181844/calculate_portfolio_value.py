def calculate_portfolio_value(self, market):
        total_value = self.balance
        for stock, quantity in self.portfolio.items():
            current_price = market.get_stock_price(stock)
            if current_price:
                total_value += quantity * current_price
        return total_value