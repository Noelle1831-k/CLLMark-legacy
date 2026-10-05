def __str__(self):
        '''
        Returns a string representation of the expense.
        :return: A string representing the expense.
        '''
        return f"Date: {self.date}, Category: {self.category}, Amount: {self.amount}"