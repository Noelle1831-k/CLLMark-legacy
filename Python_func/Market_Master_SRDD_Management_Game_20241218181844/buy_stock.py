def buy_stock(self, stock, quantity, price):
        total_cost = quantity * price
        if total_cost > self.balance:
            print("Insufficient funds!")
        else:
            self.balance -= total_cost
            self.portfolio[stock] = self.portfolio.get(stock, 0) + quantity
            print(f"Bought {quantity} shares of {stock} at ${price:.2f}.")