def check_limit(self, expenses):
        '''
        Checks if expenses exceed the budget limit.
        '''
        total = sum(expense.amount for expense in expenses if expense.category == self.category)
        return total <= self.limit