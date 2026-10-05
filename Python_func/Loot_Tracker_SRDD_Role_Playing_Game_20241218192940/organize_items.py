def organize_items(self, key='name'):
        """
        Organizes items in the inventory based on a specific attribute.
        """
        valid_keys = {'name', 'category', 'quantity', 'expiration_date'}
        if key not in valid_keys:
            print(f"Error: Invalid key '{key}'. Valid keys are {valid_keys}.")
            return
        self.items.sort(key=lambda x: getattr(x, key) if getattr(x, key) else "")
        print(f"Items organized by '{key}'.")