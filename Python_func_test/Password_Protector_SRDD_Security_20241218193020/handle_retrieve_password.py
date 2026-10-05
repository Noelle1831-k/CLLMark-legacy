def handle_retrieve_password(self):
        account = input("Enter account name: ")
        password = self.password_manager.get_password(account)
        if password:
            print(f"Password for {account}: {password}")
        else:
            print("Account not found.")