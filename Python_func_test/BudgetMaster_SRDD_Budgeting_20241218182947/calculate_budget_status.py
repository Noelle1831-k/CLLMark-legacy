def calculate_budget_status(income, categorized_data, budget_goal):
    total_expenses = sum(categorized_data.values())
    remaining_budget = income - total_expenses
    return {'total_expenses': total_expenses, 'remaining_budget': remaining_budget, 'budget_goal': budget_goal}