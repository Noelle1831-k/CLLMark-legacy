def get_balance(self):
        total_income = sum(item["amount"] for item in self.income)
        total_expenses = sum(item["amount"] for item in self.expenses)
        return total_income - total_expenses