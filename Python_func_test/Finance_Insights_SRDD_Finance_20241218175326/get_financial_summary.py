def get_financial_summary(self):
        '''
        Get a summary of income and expenses.
        '''
        total_income = sum(item['amount'] for item in self.income)
        total_expenses = sum(item['amount'] for item in self.expenses)
        return {
            'total_income': total_income,
            'total_expenses': total_expenses,
            'net_savings': total_income - total_expenses
        }