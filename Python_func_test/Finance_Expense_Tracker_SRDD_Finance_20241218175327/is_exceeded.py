def is_exceeded(self, expenses):
        '''
        Checks if the budget is exceeded.
        :param expenses: List of expenses in the category.
        :return: True if the budget is exceeded, False otherwise.
        '''
        total_expense = sum(expenses)
        return total_expense > self.amount