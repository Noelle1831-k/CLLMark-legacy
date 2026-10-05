def calculate_remaining_income(self):
        total_expenses = sum([expense.get_amount() for expense in self.expenses])
        return self.income - total_expenses