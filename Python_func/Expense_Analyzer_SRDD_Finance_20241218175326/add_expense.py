def add_expense(self, amount, category):
        '''
        Add a new expense to the list of expenses.
        '''
        expense = Expense(amount, category)
        self.expenses.append(expense)