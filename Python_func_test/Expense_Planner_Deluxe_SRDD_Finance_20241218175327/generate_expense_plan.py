def generate_expense_plan(self):
        total_income = self.user.income
        savings_goal = self.user.savings_goal
        allocated_budget = total_income - savings_goal
        if not self.categories:
            self.notification_system.send_alert("No categories available to allocate budget.")
            return
        for category in self.categories:
            category.allocate_budget(allocated_budget / len(self.categories))
        self.forecasting.forecast_expenses(self.categories)
        self.notification_system.send_alert("Expense plan generated successfully.")