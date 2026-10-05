def buy_stocks(self):
        stock = input("Enter stock symbol to buy: ").upper()
        quantity = int(input("Enter quantity to buy: "))
        price = self.market.get_stock_price(stock)
        if price:
            self.player.buy_stock(stock, quantity, price)
        else:
            print(f"Stock {stock} not found!")