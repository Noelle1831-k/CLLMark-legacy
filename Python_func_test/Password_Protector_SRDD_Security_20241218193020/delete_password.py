def delete_password(self, account):
        # Delete the password for the specified account
        if account in self.passwords:
            del self.passwords[account]