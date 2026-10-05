def generate_report(self, income_tracker, expense_tracker, budget_goal):
        total_income = income_tracker.get_total_income()
        total_expenses = expense_tracker.get_total_expenses()
        goal_achieved = budget_goal.check_goal_progress(total_income, total_expenses)
        print(f"Total Income: {total_income}")
        print(f"Total Expenses: {total_expenses}")
        print(f"Budget Goal Achieved: {'Yes' if goal_achieved else 'No'}")