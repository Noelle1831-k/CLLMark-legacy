def remove_expense(self, description):
        '''
        Removes an expense from the list by its description.
        '''
        self.expenses = [e for e in self.expenses if not (e.description == description)]