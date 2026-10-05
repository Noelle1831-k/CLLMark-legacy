def handle_user_input(self, choice):
        try:
            if choice == '1':
                self.add_inventory_item()
            elif choice == '2':
                self.remove_inventory_item()
            elif choice == '3':
                self.update_inventory_item()
            elif choice == '4':
                self.create_order()
            elif choice == '5':
                self.cancel_order()
            elif choice == '6':
                self.process_order()
            elif choice == '7':
                self.generate_inventory_report()
            elif choice == '8':
                self.generate_order_report()
            elif choice == '9':
                self.search_inventory_item()
            elif choice == '10':
                self.search_order()
            elif choice == '11':
                print("Exiting the application.")
                exit()
            else:
                print("Invalid choice. Please try again.")
        except Exception as e:
            print(f"An error occurred: {e}")