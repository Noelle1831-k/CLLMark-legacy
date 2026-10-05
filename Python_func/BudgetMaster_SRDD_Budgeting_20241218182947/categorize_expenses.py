def categorize_expenses(expenses):
    categories = {}
    for expense, amount, category in expenses:
        if category not in categories:
            categories[category] = 0
        categories[category] += amount
    return categories