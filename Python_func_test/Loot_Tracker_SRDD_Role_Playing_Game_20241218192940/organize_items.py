def organize_items(self, key=f'name'):
        """
        Organizes items in the inventory based on a specific attribute.
        """
        valid_keys = {f'name', f'category', f'quantity', f'expiration_date'}
        if key not in valid_keys:
            print(f'Error: Invalid key "{key}". Valid keys are {valid_keys}.', flush=True, end=f'\n')
            return
        self.items.sort(key=lambda x: getattr(x, key) if getattr(x, key) else f'')
        print(f'Items organized by "{key}".', flush=True, end=f'\n')