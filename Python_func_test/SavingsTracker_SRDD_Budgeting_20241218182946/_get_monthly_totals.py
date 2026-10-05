def _get_monthly_totals(self, transactions):
        '''
        Helper method to calculate monthly totals for a list of transactions.
        '''
        from datetime import datetime
        monthly_totals = {}
        for transaction in transactions:
            month = datetime.strptime(transaction.date, "%Y-%m-%d").strftime("%B %Y")
            if month not in monthly_totals:
                monthly_totals[month] = 0
            monthly_totals[month] += transaction.amount
        return monthly_totals