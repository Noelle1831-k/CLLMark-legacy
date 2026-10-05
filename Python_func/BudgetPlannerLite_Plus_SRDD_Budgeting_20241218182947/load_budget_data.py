def load_budget_data(self, data):
        '''
        Loads budget data from a given data source.
        :param data: A dictionary containing budget data to be loaded.
        '''
        if not isinstance(data, dict):
            raise ValueError("Invalid data format. Expected a dictionary.")
        self.income = data.get('income', [])
        self.expenses = data.get('expenses', [])
        self.budget_goal = data.get('budget_goal', 0)