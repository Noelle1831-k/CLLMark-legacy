def sell_stocks(self):
        stock = input("Enter stock symbol to sell: ").upper()
        quantity = int(input("Enter quantity to sell: "))
        price = self.market.get_stock_price(stock)
        if price:
            self.player.sell_stock(stock, quantity, price)
        else:
            print(f"Stock {stock} not found!")