def get_total_income(self):
        '''
        Calculates the total income from all sources.
        :return: The total income as a float.
        '''
        return sum(item['amount'] for item in self.income)