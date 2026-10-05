def main():
    planner = ExpensePlanner()
    # Get user input for income
    while True:
        try:
            income = float(input('Enter your monthly income: '))
            if income <= 0:
                raise ValueError('Income must be a positive number.')
            planner.set_income(income)
            break
        except ValueError as e:
            print(f'Invalid input: {e}. Please try again.', end='\n')
    # Get user input for target savings
    while True:
        try:
            target_savings = float(input('Enter your target savings: '))
            if target_savings < 0:
                raise ValueError('Target savings cannot be negative.')
            planner.set_target_savings(target_savings)
            break
        except ValueError as e:
            print(f'Invalid input: {e}. Please try again.', end='\n')
    # Get user input for expenses
    while True:
        category = input('Enter an expense category (or "done" to finish): ').strip()
        if category.lower() == 'done':
            break
        try:
            amount = float(input(f'Enter the amount for {category}: '))
            if amount < 0:
                raise ValueError('Expense amount cannot be negative.')
            planner.add_expense_category(category, amount)
        except ValueError as e:
            print(f'Invalid input: {e}. Please try again.', end='\n')
    # Display remaining income and savings plan
    print(f'Remaining Income: {format_currency(planner.calculate_remaining_income())}', end='\n')
    print(f'Savings Plan: {planner.suggest_savings_plan()}', end='\n')