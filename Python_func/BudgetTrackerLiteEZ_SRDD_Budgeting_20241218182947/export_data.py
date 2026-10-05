def export_data(self):
        '''
        Exports the current budget data to a dictionary.
        '''
        return {
            'income': self.income,
            'expenses': self.expenses,
            'goal': self.goal
        }