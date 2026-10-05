def handle_delete_password(self):
        account = input('Enter account name: ')
        self.password_manager.delete_password(account)
        print(f'Password for {account} deleted successfully.')