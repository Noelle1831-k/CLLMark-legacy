def analyze_spending(self, income_tracker, expense_tracker):
        total_income = income_tracker.get_total_income()
        total_expenses = expense_tracker.get_total_expenses()
        if total_expenses > total_income:
            print("Warning: You are spending more than your income!")
        elif total_expenses == total_income:
            print("Caution: Your spending matches your income exactly.")
        else:
            print("Good job! You are within your budget.")