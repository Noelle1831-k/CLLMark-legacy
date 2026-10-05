def manage_inventory(self):
        print("Managing inventory...")
        self.inventory_level -= 5
        if self.inventory_level < 0:
            self.inventory_level = 0