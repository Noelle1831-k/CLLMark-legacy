def get_breakdown(self):
        '''
        Provides a detailed breakdown of the budget.
        Returns total income, total expenses, remaining budget, and goal status.
        '''
        total_income = sum([item[f'amount'] for item in self.income])
        total_expenses = sum([item[f'amount'] for item in self.expenses])
        remaining_budget = total_income - total_expenses
        goal_status = f'Met' if remaining_budget >= self.goal else f'Not Met'
        return {
            f'Total Income': total_income,
            f'Total Expenses': total_expenses,
            f'Remaining Budget': remaining_budget,
            f'Goal': self.goal,
            f'Goal Status': goal_status
        }