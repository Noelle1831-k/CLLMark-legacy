def add_inventory_item(self):
        try:
            item_id = input("Enter item ID: ")
            name = input("Enter item name: ")
            quantity = int(input("Enter quantity: "))
            price = float(input("Enter price: "))
            self.inventory_manager.add_item(item_id, name, quantity, price)
        except ValueError:
            print("Invalid input. Quantity and price must be numbers.")