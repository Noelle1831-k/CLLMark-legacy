def manage_inventory(self):
        '''
        Manage the inventory by checking stock and ordering items.
        '''
        self.inventory.check_stock()
        # Simulate ordering items if stock is low
        for item, quantity in self.inventory.items.items():
            if quantity < 10:
                self.inventory.add_item(item, 20)
                self.expenses += 50  # Assume each order costs $50
                print(f"Ordered more {item}. New quantity: {self.inventory.items[item]}")