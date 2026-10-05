def search_inventory_item(self):
        item_id = input("Enter item ID to search: ")
        self.inventory_manager.search_item(item_id)