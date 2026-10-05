def get_total_expenses(self):
        '''
        Calculates the total amount of all expenses.
        '''
        return sum(expense.amount for expense in self.expenses)