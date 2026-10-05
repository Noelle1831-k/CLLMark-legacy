def sell_stock(self, stock, quantity, price):
        if stock not in self.portfolio or self.portfolio[stock] < quantity:
            print("Not enough shares to sell!")
        else:
            self.portfolio[stock] -= quantity
            self.balance += quantity * price
            print(f"Sold {quantity} shares of {stock} at ${price:.2f}.")