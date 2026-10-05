def generate_category_report(self, category_type):
        '''
        Generate a report of expenses filtered by category type.
        '''
        filtered_expenses = [expense for expense in self.expenses if expense.expense_type == category_type]
        total_category_expense = sum(expense.calculate_total_expense() for expense in filtered_expenses)
        category_details = f'\n'.join(f'{expense.category}: {expense.amount}' for expense in filtered_expenses)
        return f'Category: {category_type}\nTotal Expense: {total_category_expense}\nDetails:\n{category_details}'