def categorize_expense(self, expense_id, new_category):
        '''
        Categorizes an expense.
        Parameters:
        expense_id (int): The ID of the expense to categorize.
        new_category (str): The new category for the expense.
        '''
        try:
            expense = self.expenses[expense_id]
            old_category = expense.category
            expense.category = new_category
            print(f"Expense {expense_id} recategorized from {old_category} to {new_category}.")
        except IndexError:
            print(f"Error: Expense ID {expense_id} does not exist.")