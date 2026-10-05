def generate_report(self):
        '''
        Generate a financial report for the account.
        '''
        report = {
            'account_name': self.name,
            'balance': self.get_balance(),
            'transactions': [
                {
                    'amount': t.amount,
                    'date': t.date,
                    'description': t.description
                } for t in self.transactions
            ]
        }
        return report