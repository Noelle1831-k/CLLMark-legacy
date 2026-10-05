def add_expense(self, amount, category):
        '''
        Adds an expense to the budget.
        Each expense is represented as a dictionary with an amount and category.
        '''
        self.expenses.append({'amount': amount, 'category': category})