def get_stock_price(self, stock):
        self.generate_market_data()
        return self.stocks.get(stock)