def generate_reports(processed_data):
    budget_status = processed_data['budget_status']
    print("\n--- Budget Report ---")
    print(f"Total Expenses: {budget_status['total_expenses']}")
    print(f"Remaining Budget: {budget_status['remaining_budget']}")
    print(f"Budget Goal: {budget_status['budget_goal']}")
    if budget_status['remaining_budget'] < 0:
        print("Warning: You have exceeded your budget goal!")
    else:
        print("You are within your budget goal.")