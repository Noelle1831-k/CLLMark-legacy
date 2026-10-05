def process_trade(self, buyer, item_name):
        item = next((i for i in self.items if i.name == item_name), None)
        if item and buyer.username in [user.username for user in self.users]:
            if buyer.balance >= item.price:
                buyer.balance -= item.price
                seller = next((u for u in self.users if u.username == item.owner), None)
                if seller:
                    seller.balance += item.price
                item.owner = buyer.username
                print(f"Trade successful: {item.name} bought by {buyer.username}.")
            else:
                print("Trade failed: Buyer does not have enough funds.")
        else:
            print("Trade failed: Item or buyer not found.")