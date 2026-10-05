def main():
    # Initialize ExpenseManager
    expense_manager = ExpenseManager()
    # User input for expenses
    while True:
        try:
            amount = float(input("Enter expense amount (or '0' to finish): "))
            if amount == 0:
                break
            category = input("Enter expense category: ")
            date = input("Enter expense date (YYYY-MM-DD): ")
            expense_manager.add_expense(Expense(amount, category, date))
        except ValueError:
            print("Invalid input. Please enter a valid number for the amount.")
    # User input for budget
    category_budgets = {}
    while True:
        category = input("Enter budget category (or 'done' to finish): ")
        if category.lower() == 'done':
            break
        try:
            budget_amount = float(input(f"Enter budget amount for {category}: "))
            category_budgets[category] = budget_amount
        except ValueError:
            print("Invalid input. Please enter a valid number for the budget amount.")
    # Initialize Budget
    budget = Budget(category_budgets)
    # Generate visualizations
    visualization = Visualization(expense_manager.get_expenses_summary(), budget)
    visualization.generate_pie_chart()
    visualization.generate_bar_chart()
    # Generate tips
    tips = Tips(expense_manager.get_expenses_summary(), budget)
    tips.generate_tips()