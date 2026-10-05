def input_expense(self, amount, description, category, date):
        '''
        Input a new expense, categorize it, and add to the list.
        '''
        expense = Expense(amount, description, category, date)
        self.expenses.append(expense)
        self.category_manager.categorize_expense(expense)
        self.data_storage.save_expenses_to_file('expenses.json', self.expenses)