def categorize_expenses(self):
        categorized_expenses = {}
        for category, amount in self.expenses.items():
            categorized_expenses[category] = format_currency(amount)
        return categorized_expenses