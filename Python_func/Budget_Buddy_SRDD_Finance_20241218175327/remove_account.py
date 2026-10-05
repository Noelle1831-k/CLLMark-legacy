def remove_account(self, account_name):
        self.accounts = [acc for acc in self.accounts if acc.name != account_name]