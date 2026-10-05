def get_total_expenses(self):
        '''
        Calculates the total expenses across all categories.
        :return: The total expenses as a float.
        '''
        return sum(item['amount'] for item in self.expenses)