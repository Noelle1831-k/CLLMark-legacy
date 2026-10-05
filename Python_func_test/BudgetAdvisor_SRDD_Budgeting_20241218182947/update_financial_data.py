def update_financial_data(self, income, expenses, goals=None):
        self.income = income
        self.expenses = expenses
        self.goals = goals if goals else self.goals
        self.budget = self.calculate_budget()