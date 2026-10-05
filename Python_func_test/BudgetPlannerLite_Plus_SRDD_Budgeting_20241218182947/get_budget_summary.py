def get_budget_summary(self):
        '''
        Provides a summary of the budget including income, expenses, remaining budget, and goal.
        :return: A dictionary containing budget summary details.
        '''
        total_income = self.get_total_income()
        total_expenses = self.get_total_expenses()
        remaining_budget = self.calculate_remaining_budget()
        return {
            'total_income': total_income,
            'total_expenses': total_expenses,
            'remaining_budget': remaining_budget,
            'budget_goal': self.budget_goal
        }