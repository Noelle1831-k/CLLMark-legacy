def calculate_optimal_plan(self):
        remaining_income = self.income - sum([expense.get_amount() for expense in self.expenses])
        if (self.target_savings < remaining_income or self.target_savings == remaining_income):
            return f'You can save {self.target_savings} and still have {remaining_income - self.target_savings} left.'
        else:
            return f'You need to reduce your expenses by {self.target_savings - remaining_income} to meet your savings goal.'