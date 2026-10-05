def add_item(self, name, category, quantity=1, description=None, expiration_date=None):
        """
        Adds an item to the inventory and schedules a notification if needed.
        """
        if quantity < 1:
            print("Error: Quantity must be at least 1.")
            return
        item = Item(name, category, quantity, description, expiration_date)
        self.items.append(item)
        self.notification_system.schedule_notification(item)
        print(f"Item '{name}' added successfully.")