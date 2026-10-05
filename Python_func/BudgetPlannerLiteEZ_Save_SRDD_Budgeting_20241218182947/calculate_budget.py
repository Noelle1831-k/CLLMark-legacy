def calculate_budget(self):
        total_income = sum(self.income)
        total_expenses = sum(self.expenses)
        savings = total_income - total_expenses
        remaining_to_goal = max(0, self.savings_goal - savings)
        return {
            "Total Income": total_income,
            "Total Expenses": total_expenses,
            "Savings": savings,
            "Savings Goal": self.savings_goal,
            "Remaining to Goal": remaining_to_goal
        }