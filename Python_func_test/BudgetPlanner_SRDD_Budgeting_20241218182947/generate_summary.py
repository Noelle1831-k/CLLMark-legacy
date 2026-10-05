def generate_summary(self):
        '''
        Generate a summary report of total income, total expense, and balance.
        '''
        total_income = sum(income.calculate_total_income() for income in self.incomes)
        total_expense = sum(expense.calculate_total_expense() for expense in self.expenses)
        balance = total_income - total_expense
        return f"Total Income: {total_income}\nTotal Expense: {total_expense}\nBalance: {balance}"