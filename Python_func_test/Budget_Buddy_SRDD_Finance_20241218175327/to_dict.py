def to_dict(self):
        '''
        Convert user data to dictionary.
        '''
        return {
            'accounts': [
                {
                    'name': acc.name,
                    'transactions': [
                        {
                            'amount': t.amount,
                            'date': t.date,
                            'description': t.description
                        } for t in acc.transactions
                    ]
                } for acc in self.accounts
            ],
            'budgets': self.budget.budgets
        }