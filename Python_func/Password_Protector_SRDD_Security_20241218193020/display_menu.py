def display_menu(self):
        while True:
            print("\nPassword Protector Menu:")
            print("1. Add Password")
            print("2. Retrieve Password")
            print("3. Delete Password")
            print("4. Generate Password")
            print("5. Sync Password")
            print("6. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.handle_add_password()
            elif choice == '2':
                self.handle_retrieve_password()
            elif choice == '3':
                self.handle_delete_password()
            elif choice == '4':
                self.handle_generate_password()
            elif choice == '5':
                self.handle_sync_password()
            elif choice == '6':
                break
            else:
                print("Invalid choice. Please try again.")