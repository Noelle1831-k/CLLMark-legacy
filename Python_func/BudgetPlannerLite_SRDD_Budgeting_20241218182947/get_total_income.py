def get_total_income(self):
        '''
        Calculate the total income.
        '''
        return sum(income.amount for income in self.incomes)