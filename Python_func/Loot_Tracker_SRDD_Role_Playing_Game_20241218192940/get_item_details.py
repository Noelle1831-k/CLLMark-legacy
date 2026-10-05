def get_item_details(self, item_name):
        """
        Retrieves detailed information about a specific item.
        """
        for item in self.items:
            if item.name == item_name:
                return item.details()
        return f"Error: Item '{item_name}' not found."