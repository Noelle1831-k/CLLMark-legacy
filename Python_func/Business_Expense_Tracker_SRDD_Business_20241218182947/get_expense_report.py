def get_expense_report(self):
        '''
        Returns a report of all expenses in dictionary format.
        '''
        return [e.to_dict() for e in self.expenses]