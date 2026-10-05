def render_calendar(self):
        # Simulate rendering a calendar view
        print("Rendering calendar view...")
        for income in self.incomes:
            print(f"Income: {income.name}, Amount: {income.amount}, Next Due: {income.calculate_next_due_date()}")
        for expense in self.expenses:
            print(f"Expense: {expense.name}, Amount: {expense.amount}, Next Due: {expense.calculate_next_due_date()}")