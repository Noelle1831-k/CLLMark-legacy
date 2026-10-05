def get_breakdown(self):
        '''
        Provides a detailed breakdown of the budget.
        Returns total income, total expenses, remaining budget, and goal status.
        '''
        total_income = sum([item['amount'] for item in self.income])
        total_expenses = sum([item['amount'] for item in self.expenses])
        remaining_budget = total_income - total_expenses
        goal_status = "Met" if remaining_budget >= self.goal else "Not Met"
        return {
            "Total Income": total_income,
            "Total Expenses": total_expenses,
            "Remaining Budget": remaining_budget,
            "Goal": self.goal,
            "Goal Status": goal_status
        }