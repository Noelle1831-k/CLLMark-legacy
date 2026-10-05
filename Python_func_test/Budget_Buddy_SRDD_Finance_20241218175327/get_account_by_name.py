def get_account_by_name(self, name):
        for account in self.accounts:
            if account.name == name:
                return account
        return None