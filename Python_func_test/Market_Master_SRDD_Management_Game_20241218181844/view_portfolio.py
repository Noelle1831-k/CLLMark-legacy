def view_portfolio(self):
        print(f"\n=== {self.name}'s Portfolio ===")
        for stock, quantity in self.portfolio.items():
            print(f"{stock}: {quantity} shares")
        print(f"Balance: ${self.balance:.2f}")