def handle_add_password(self):
        account = input("Enter account name: ")
        password = input("Enter password: ")
        self.password_manager.add_password(account, password)
        print(f"Password for {account} added successfully.")