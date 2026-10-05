def main():
    data_manager = DataManager()
    user_data = data_manager.load_data()
    budget_monitor = BudgetMonitor(user_data)
    while True:
        print("\nBudgetMonitor Menu:")
        print("1. Add Income")
        print("2. Add Expense")
        print("3. Set Budget Goal")
        print("4. Generate Report")
        print("5. Exit")
        choice = input("Choose an option: ")
        if choice == '1':  # Add Income
            amount = get_valid_number("Enter income amount: ")
            category = input("Enter income category: ")
            budget_monitor.add_income(amount, category)
        elif choice == '2':  # Add Expense
            amount = get_valid_number("Enter expense amount: ")
            category = input("Enter expense category: ")
            budget_monitor.add_expense(amount, category)
        elif choice == '3':  # Set Budget Goal
            goal = get_valid_number("Enter monthly budget goal: ")
            budget_monitor.set_budget_goal(goal)
        elif choice == '4':  # Generate Report
            budget_monitor.generate_report()
        elif choice == '5':  # Exit
            data_manager.save_data(budget_monitor.get_user_data())
            break
        else:
            print("Invalid choice. Please try again.")