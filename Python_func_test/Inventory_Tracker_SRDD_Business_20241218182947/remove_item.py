def remove_item(self, item_id):
        if item_id in self.items:
            del self.items[item_id]
            print(f"Item with ID {item_id} removed successfully.")
        else:
            print(f"Item with ID {item_id} does not exist.")