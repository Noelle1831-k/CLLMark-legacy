def add_income(self, amount, source):
        '''
        Adds income to the budget.
        Arguments:
        amount -- The amount of income to be added.
        source -- The source of the income.
        '''
        self.income.append({'amount': amount, 'source': source})