def calculate_progress():
    total_savings = sum(savings_manager.get_savings_data())
    if savings_goal == 0:
        return 0
    return (total_savings / savings_goal) * 100