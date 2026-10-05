def run(self):
        """
        Runs the main loop for the user interface.
        """
        while True:
            try:
                print("\nInventory Management System")
                print("1. Add Item")
                print("2. Remove Item")
                print("3. Organize Items")
                print("4. View Item Details")
                print("5. Search Items")
                print("6. View Notifications")
                print("7. Exit")
                choice = input("Choose an option: ")
                if choice == '1':
                    name = input("Enter item name: ")
                    category = input("Enter item category: ")
                    quantity = int(input("Enter quantity (default is 1): "))
                    description = input("Enter item description (optional): ")
                    expiration_date = input("Enter expiration date (YYYY-MM-DD) or leave blank: ")
                    self.inventory_manager.add_item(name, category, quantity, description, expiration_date)
                elif choice == '2':
                    item_name = input("Enter item name to remove: ")
                    self.inventory_manager.remove_item(item_name)
                elif choice == '3':
                    key = input("Organize by (name/category/quantity/expiration_date): ")
                    self.inventory_manager.organize_items(key)
                elif choice == '4':
                    item_name = input("Enter item name to view details: ")
                    print(self.inventory_manager.get_item_details(item_name))
                elif choice == '5':
                    query = input("Enter search query: ")
                    results = self.inventory_manager.search_items(query)
                    for result in results:
                        print(result)
                elif choice == '6':
                    notifications = self.inventory_manager.notification_system.get_notifications()
                    for notification in notifications:
                        print(notification)
                elif choice == '7':
                    print("Exiting the Inventory Management System. Goodbye!")
                    break
                else:
                    print("Invalid option. Please try again.")
            except ValueError as ve:
                print(f"Input error: {ve}")
            except Exception as e:
                print(f"An unexpected error occurred: {e}")