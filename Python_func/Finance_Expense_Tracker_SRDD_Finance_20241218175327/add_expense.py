def add_expense(self, category, amount, date):
        '''
        Adds an expense to the tracker.
        :param category: Category of the expense.
        :param amount: Amount of the expense.
        :param date: Date of the expense.
        '''
        expense = Expense(category, amount, date)
        self.expenses.append(expense)