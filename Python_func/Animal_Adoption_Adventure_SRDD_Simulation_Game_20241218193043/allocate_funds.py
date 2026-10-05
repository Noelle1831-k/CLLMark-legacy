def allocate_funds(self, amount):
        if amount <= self.funds:
            self.funds -= amount
            print(f"Allocated ${amount} for center operations. Remaining funds: ${self.funds}")
        else:
            print("Insufficient funds for allocation.")