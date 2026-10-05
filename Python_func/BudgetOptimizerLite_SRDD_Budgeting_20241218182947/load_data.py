def load_data(self, data):
        '''
        Loads budget data into the application.
        Arguments:
        data -- A dictionary containing the budget data to be loaded.
        '''
        self.income = data['income']
        self.expenses = data['expenses']
        self.goals = data['goals']