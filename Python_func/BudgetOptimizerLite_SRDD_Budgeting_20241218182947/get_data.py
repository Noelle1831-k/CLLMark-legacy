def get_data(self):
        '''
        Returns all the data (income, expenses, and goals) of the budget.
        Returns:
        data -- A dictionary containing all budget data.
        '''
        return {'income': self.income, 'expenses': self.expenses, 'goals': self.goals}