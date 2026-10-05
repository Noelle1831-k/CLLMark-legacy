def password_management(self, password_manager):
        '''Interactively manage passwords.'''
        self.display("\n--- Password Manager ---")
        while True:
            self.display("1. Store a Password")
            self.display("2. Retrieve a Password")
            self.display("3. Go Back to Main Menu")
            choice = self.get_user_input("Enter your choice: ")
            if choice == "1":
                account = self.get_user_input("Enter the account name: ")
                password = self.get_user_input("Enter the password: ")
                password_manager.store_password(account, password)
            elif choice == "2":
                account = self.get_user_input("Enter the account name: ")
                retrieved_password = password_manager.retrieve_password(account)
                self.display(f"Retrieved password: {retrieved_password}")
            elif choice == "3":
                break
            else:
                self.display("Invalid choice. Please try again.")