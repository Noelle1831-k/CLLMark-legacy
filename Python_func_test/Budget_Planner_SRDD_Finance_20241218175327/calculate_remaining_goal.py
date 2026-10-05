def calculate_remaining_goal(self, total_income, total_expenses):
        current_savings = total_income - total_expenses
        self.savings_history.append(current_savings)
        return self.goal - current_savings