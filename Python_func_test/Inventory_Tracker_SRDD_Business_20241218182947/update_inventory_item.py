def update_inventory_item(self):
        try:
            item_id = input("Enter item ID to update: ")
            quantity = int(input("Enter new quantity: "))
            price = float(input("Enter new price: "))
            self.inventory_manager.update_item(item_id, quantity, price)
        except ValueError:
            print("Invalid input. Quantity and price must be numbers.")