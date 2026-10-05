def suggest_savings_plan(self):
        remaining_income = self.calculate_remaining_income()
        savings_plan = SavingsPlan(self.target_savings, self.income, self.expenses)
        return savings_plan.calculate_optimal_plan()