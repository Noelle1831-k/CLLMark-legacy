def add_income(self, amount, source):
        '''
        Adds income to the budget.
        Each income is represented as a dictionary with an amount and source.
        '''
        self.income.append({'amount': amount, 'source': source})