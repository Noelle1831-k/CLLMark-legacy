def load_from_dict(self, data):
        '''
        Load user data from dictionary.
        '''
        self.accounts = [Account(acc['name']) for acc in data.get('accounts', [])]
        for acc, acc_data in zip(self.accounts, data.get('accounts', [])):
            acc.transactions = [Transaction(t['amount'], t['date'], t['description']) for t in acc_data.get('transactions', [])]
        self.budget.budgets = data.get('budgets', {})