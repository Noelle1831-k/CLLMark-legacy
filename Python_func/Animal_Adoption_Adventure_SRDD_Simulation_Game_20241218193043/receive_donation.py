def receive_donation(self, amount):
        self.funds += amount
        print(f"Received donation of ${amount}. Total funds: ${self.funds}")