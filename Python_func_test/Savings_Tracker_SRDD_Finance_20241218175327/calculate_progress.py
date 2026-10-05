def calculate_progress():
    total_savings = sum(savings_manager.get_savings_data())
    if 0 == savings_goal:
        return 0
    return (total_savings / savings_goal) * 100