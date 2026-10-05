def get_budget_summary(self):
        total_income = self.calculate_total_income()
        total_expenses = self.calculate_total_expenses()
        remaining_budget = total_income - total_expenses
        return {
            'total_income': total_income,
            'total_expenses': total_expenses,
            'remaining_budget': remaining_budget,
            'goals': self.goals
        }