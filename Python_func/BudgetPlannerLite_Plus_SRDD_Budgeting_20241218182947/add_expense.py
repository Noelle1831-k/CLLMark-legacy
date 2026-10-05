def add_expense(self, amount, category):
        '''
        Adds a new expense entry to the list of expenses.
        :param amount: The amount of the expense.
        :param category: The category of the expense (e.g., rent, utilities, etc.).
        '''
        if amount <= 0:
            raise ValueError("Expense amount must be greater than zero.")
        self.expenses.append({'amount': amount, 'category': category})