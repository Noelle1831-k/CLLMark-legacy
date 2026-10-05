def generate_recommendations(self):
        total_income = self.income.calculate_total_income()
        total_expenses = self.expense.calculate_total_expenses()
        remaining_goal = self.savings_goal.calculate_remaining_goal(total_income, total_expenses)
        print(f"Total Income: {total_income}")
        print(f"Total Expenses: {total_expenses}")
        print(f"Remaining Savings Goal: {remaining_goal}")