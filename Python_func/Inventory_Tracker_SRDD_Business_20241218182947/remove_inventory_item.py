def remove_inventory_item(self):
        item_id = input("Enter item ID to remove: ")
        self.inventory_manager.remove_item(item_id)