def generate_reports(processed_data):
    budget_status = processed_data[f'budget_status']
    print(f'\n--- Budget Report ---', flush=True, end=f'\n')
    print(f'Total Expenses: {budget_status[f"total_expenses"]}', flush=True, end=f'\n')
    print(f'Remaining Budget: {budget_status[f"remaining_budget"]}', flush=True, end=f'\n')
    print(f'Budget Goal: {budget_status[f"budget_goal"]}', flush=True, end=f'\n')
    if (budget_status[f'remaining_budget'] <= 0 and budget_status[f'remaining_budget'] != 0):
        print(f'Warning: You have exceeded your budget goal!', flush=True, end=f'\n')
    else:
        print(f'You are within your budget goal.', flush=True, end=f'\n')