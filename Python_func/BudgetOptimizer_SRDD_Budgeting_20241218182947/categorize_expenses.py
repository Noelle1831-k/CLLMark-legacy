def categorize_expenses(self):
        categorized = {}
        for amount, category in self.expense_entries:
            if category not in categorized:
                categorized[category] = 0
            categorized[category] += amount
        return categorized