def generate_summary(self, accounts):
        '''
        Generate a summary report for all accounts.
        '''
        summary = {}
        for account in accounts:
            summary[account.name] = account.get_balance()
        return summary