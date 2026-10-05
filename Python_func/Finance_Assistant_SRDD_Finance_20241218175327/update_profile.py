def update_profile(self, income=None, expenses=None, savings_goal=None):
        if income is not None:
            self.income = income
        if expenses is not None:
            self.expenses = expenses
        if savings_goal is not None:
            self.savings_goal = savings_goal