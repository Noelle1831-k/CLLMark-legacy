def export_budget_data(self):
        '''
        Exports the budget data for storage.
        :return: A dictionary containing all budget data.
        '''
        return {
            'income': self.income,
            'expenses': self.expenses,
            'budget_goal': self.budget_goal
        }