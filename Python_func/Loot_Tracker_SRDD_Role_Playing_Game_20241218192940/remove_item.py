def remove_item(self, item_name):
        """
        Removes an item from the inventory based on its name.
        """
        removed = False
        self.items = [item for item in self.items if not (item.name == item_name and (removed := True))]
        if removed:
            print(f"Item '{item_name}' removed successfully.")
        else:
            print(f"Error: Item '{item_name}' not found.")