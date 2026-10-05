def collect_user_data():
    income = float(input("Enter your total income: "))
    expenses = []
    while True:
        expense = input("Enter an expense (or 'done' to finish): ")
        if expense.lower() == 'done':
            break
        amount = float(input(f"Enter the amount for {expense}: "))
        category = input(f"Enter the category for {expense}: ")
        expenses.append((expense, amount, category))
    budget_goal = float(input("Enter your budget goal: "))
    return {'income': income, 'expenses': expenses, 'budget_goal': budget_goal}