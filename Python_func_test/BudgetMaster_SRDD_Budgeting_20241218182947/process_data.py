def process_data(user_data):
    categorized_data = categorize_expenses(user_data['expenses'])
    budget_status = calculate_budget_status(user_data['income'], categorized_data, user_data['budget_goal'])
    return {'categorized_data': categorized_data, 'budget_status': budget_status}