def categorize_expense(self):
        categorized_expenses = {}
        for expense in self.expenses:
            if expense["category"] in categorized_expenses:
                categorized_expenses[expense["category"]] += expense["amount"]
            else:
                categorized_expenses[expense["category"]] = expense["amount"]
        return categorized_expenses