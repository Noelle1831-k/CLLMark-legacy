def handle_sync_password(self):
        account = input("Enter account name: ")
        encrypted_password = self.password_manager.passwords.get(account)
        if encrypted_password:
            self.sync_service.sync_to_cloud(account, encrypted_password)
            print(f"Password for {account} synchronized successfully.")
        else:
            print("Account not found.")