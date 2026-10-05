def get_expense_summary(self):
        '''
        Provides a summary of expenses by category.
        '''
        summary = {}
        for expense in self.expenses:
            if expense.category in summary:
                summary[expense.category] += expense.amount
            else:
                summary[expense.category] = expense.amount
        return summary