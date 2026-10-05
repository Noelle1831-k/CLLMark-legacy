def add_expense(self, amount, category):
        '''
        Adds expense to the budget.
        Arguments:
        amount -- The amount of expense to be added.
        category -- The category of the expense.
        '''
        self.expenses.append({'amount': amount, 'category': category})