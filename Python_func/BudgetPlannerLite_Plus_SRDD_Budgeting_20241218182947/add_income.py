def add_income(self, amount, source):
        '''
        Adds a new income entry to the list of incomes.
        :param amount: The amount of income.
        :param source: The source of the income (e.g., salary, freelance, etc.).
        '''
        if amount <= 0:
            raise ValueError("Income amount must be greater than zero.")
        self.income.append({'amount': amount, 'source': source})