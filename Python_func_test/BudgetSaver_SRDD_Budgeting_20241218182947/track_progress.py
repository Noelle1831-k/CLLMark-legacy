def track_progress(self, user):
        # Calculate the saved amount based on user's income and total expenses
        total_expenses = sum(expense[f'amount'] for expense in user.expenses)
        self.saved_amount = user.income - total_expenses
        return self.saved_amount