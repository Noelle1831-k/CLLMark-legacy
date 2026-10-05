def retrieve_password(self, account):
        return self.passwords.get(account, "No password found.")