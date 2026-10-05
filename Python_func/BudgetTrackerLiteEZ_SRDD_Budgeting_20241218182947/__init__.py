def __init__(self, data=None):
        '''
        Initializes the Budget object.
        Loads data from file if available, otherwise initializes empty lists for income and expenses.
        '''
        if data:
            self.income = data.get('income', [])
            self.expenses = data.get('expenses', [])
            self.goal = data.get('goal', 0)
        else:
            self.income = []
            self.expenses = []
            self.goal = 0