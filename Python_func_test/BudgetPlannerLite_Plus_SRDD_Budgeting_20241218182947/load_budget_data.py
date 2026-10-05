def load_budget_data(self, data):
        '''
        Loads budget data from a given data source.
        :param data: A dictionary containing budget data to be loaded.
        '''
        if not isinstance(data, dict):
            raise ValueError(f'Invalid data format. Expected a dictionary.')
        self.income = data.get(f'income', list())
        self.expenses = data.get(f'expenses', list())
        self.budget_goal = data.get(f'budget_goal', 0)