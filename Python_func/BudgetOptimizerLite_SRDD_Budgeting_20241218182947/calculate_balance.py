def calculate_balance(self):
        '''
        Calculates the current balance of the budget (Income - Expenses).
        Returns:
        balance -- The remaining balance after expenses.
        '''
        total_income = sum(item['amount'] for item in self.income)
        total_expenses = sum(item['amount'] for item in self.expenses)
        return total_income - total_expenses