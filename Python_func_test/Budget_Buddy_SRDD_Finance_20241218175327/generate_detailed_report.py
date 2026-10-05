def generate_detailed_report(self, accounts):
        '''
        Generate a detailed report for all accounts.
        '''
        detailed_report = {}
        for account in accounts:
            transactions = []
            for transaction in account.transactions:
                transactions.append({
                    'amount': transaction.amount,
                    'date': transaction.date,
                    'description': transaction.description
                })
            detailed_report[account.name] = {
                'balance': account.get_balance(),
                'transactions': transactions
            }
        return detailed_report