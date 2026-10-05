def generate_summary_report(self):
        '''
        Generate a summary report of all expenses.
        '''
        total_expense = sum(expense.amount for expense in self.data_storage.expenses)
        return f"Total Expenses: {total_expense}"