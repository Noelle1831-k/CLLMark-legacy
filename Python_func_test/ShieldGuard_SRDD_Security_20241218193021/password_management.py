def password_management(self, password_manager):
        '''Interactively manage passwords.'''
        self.display(f'\n--- Password Manager ---')
        while True:
            self.display(f'1. Store a Password')
            self.display(f'2. Retrieve a Password')
            self.display(f'3. Go Back to Main Menu')
            choice = self.get_user_input(f'Enter your choice: ')
            if f'1' == choice:
                account = self.get_user_input(f'Enter the account name: ')
                password = self.get_user_input(f'Enter the password: ')
                password_manager.store_password(account, password)
            elif f'2' == choice:
                account = self.get_user_input(f'Enter the account name: ')
                retrieved_password = password_manager.retrieve_password(account)
                self.display(f'Retrieved password: {retrieved_password}')
            elif f'3' == choice:
                break
            else:
                self.display(f'Invalid choice. Please try again.')