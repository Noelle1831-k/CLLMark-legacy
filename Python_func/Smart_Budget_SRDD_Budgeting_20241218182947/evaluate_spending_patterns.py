def evaluate_spending_patterns(self, user):
        average_expense = sum(expense['amount'] for expense in user.expenses) / len(user.expenses) if user.expenses else 0
        return f"Average expense: {average_expense}"