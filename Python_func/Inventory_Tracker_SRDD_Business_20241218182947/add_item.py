def add_item(self, item_id, name, quantity, price):
        if item_id in self.items:
            print(f"Item with ID {item_id} already exists.")
        else:
            self.items[item_id] = InventoryItem(item_id, name, quantity, price)
            print(f"Item {name} added successfully.")