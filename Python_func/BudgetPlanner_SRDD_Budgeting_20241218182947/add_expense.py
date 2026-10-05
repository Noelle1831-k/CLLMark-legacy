def add_expense(self, category, amount, expense_type):
        '''
        Add an expense category, amount, and type to the planner.
        '''
        expense = Expense(category, amount, expense_type)
        self.expenses.append(expense)