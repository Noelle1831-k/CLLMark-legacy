def get_total_expenses(self):
        '''
        Calculate the total expenses.
        '''
        return sum(expense.amount for expense in self.expenses)