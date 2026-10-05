def check_goal_progress(self, total_income, total_expenses):
        savings = total_income - total_expenses
        return savings >= self.goal_amount