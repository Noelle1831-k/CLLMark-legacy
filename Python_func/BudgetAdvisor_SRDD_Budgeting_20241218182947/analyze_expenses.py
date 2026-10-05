def analyze_expenses(self):
        categorized_expenses = self.user_profile.categorize_expenses()
        analysis = "Expense Analysis:\n"
        for category, amount in categorized_expenses.items():
            analysis += f"{category}: {amount}\n"
        return analysis