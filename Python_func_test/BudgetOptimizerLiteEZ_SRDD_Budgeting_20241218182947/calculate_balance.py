def calculate_balance(self):
        '''
        Calculates the balance by subtracting total expenses from total income.
        Returns:
            float: The calculated balance.
        '''
        total_income = sum(income.amount for income in self.incomes)
        total_expense = sum(expense.amount for expense in self.expenses)
        return total_income - total_expense