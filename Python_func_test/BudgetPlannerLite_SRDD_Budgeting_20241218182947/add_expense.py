def add_expense(self, expense):
        '''
        Add an expense entry to the budget.
        '''
        if isinstance(expense, Expense) and expense.amount > 0:
            self.expenses.append(expense)
            self.db.save_expense(expense)
        else:
            raise ValueError("Invalid expense entry.")