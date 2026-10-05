def run_application():
    '''
    Initialize and run the BudgetPro application.
    '''
    user = User()
    budget_manager = BudgetManager()
    data_storage = DataStorage()
    visualization = Visualization()
    # Load existing data
    data_storage.load_data(user)
    # Main application loop
    while True:
        print("\nWelcome to BudgetPro!")
        print("1. Add Income")
        print("2. Add Expense")
        print("3. Set Budget Goal")
        print("4. View Financial Summary")
        print("5. Exit")
        choice = input("Choose an option: ")
        if choice == '1':
            amount = float(input("Enter income amount: "))
            user.add_income(amount)
        elif choice == '2':
            amount = float(input("Enter expense amount: "))
            user.add_expense(amount)
        elif choice == '3':
            goal = float(input("Set your budget goal: "))
            user.set_budget_goal(goal)
        elif choice == '4':
            summary = user.get_financial_summary()
            print(summary)
            visualization.plot_budget_breakdown(summary)
            visualization.display_spending_patterns(summary)
            # Calculate budget and generate recommendations
            remaining_budget = budget_manager.calculate_budget(user.income, user.expenses)
            recommendation = budget_manager.generate_recommendations(remaining_budget)
            print(recommendation)
        elif choice == '5':
            data_storage.save_data(user)
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")