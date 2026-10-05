def analyze_expenses(self, user):
        total_expenses = sum(expense['amount'] for expense in user.expenses)
        return f"Total expenses: {total_expenses}"