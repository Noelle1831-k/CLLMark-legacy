def update_item(self, item_id, quantity, price):
        if item_id in self.items:
            self.items[item_id].update_quantity(quantity)
            self.items[item_id].update_price(price)
            print(f"Item with ID {item_id} updated successfully.")
        else:
            print(f"Item with ID {item_id} does not exist.")