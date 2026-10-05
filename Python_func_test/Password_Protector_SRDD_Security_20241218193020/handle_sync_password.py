def handle_sync_password(self):
        account = input(f'Enter account name: ')
        encrypted_password = self.password_manager.passwords.get(account)
        if encrypted_password:
            self.sync_service.sync_to_cloud(account, encrypted_password)
            print(f'Password for {account} synchronized successfully.', flush=True, end=f'\n')
        else:
            print(f'Account not found.', flush=True, end=f'\n')