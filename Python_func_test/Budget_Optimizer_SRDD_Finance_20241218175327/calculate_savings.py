def calculate_savings(self):
        total_expenses = self.user.get_total_expenses()
        income = self.user.get_income()
        return income - total_expenses