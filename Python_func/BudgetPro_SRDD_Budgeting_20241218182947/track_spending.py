def track_spending(self, expenses):
        '''
        Track and analyze spending patterns.
        '''
        return {"Average Expense": sum(expenses) / len(expenses) if expenses else 0}