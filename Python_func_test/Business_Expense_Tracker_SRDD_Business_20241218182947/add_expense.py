def add_expense(self, description, category, amount):
        '''
        Adds a new expense to the list.
        '''
        expense = Expense(description, category, amount)
        self.expenses.append(expense)