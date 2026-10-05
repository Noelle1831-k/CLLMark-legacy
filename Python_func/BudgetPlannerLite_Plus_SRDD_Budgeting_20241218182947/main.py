def main():
    '''
    Main function to initialize and run the BudgetPlannerLite Plus application.
    '''
    planner = BudgetPlanner()
    savings = SavingsTracker()
    data_handler = DataHandler()
    visualization = Visualization()
    utilities = Utilities()
    # Load existing data
    budget_data = data_handler.load_data()
    if budget_data:
        planner.load_budget_data(budget_data)
    # User interaction
    while True:
        print("\n--- BudgetPlannerLite Plus ---")
        print("1. Add Income")
        print("2. Add Expense")
        print("3. Set Budget Goal")
        print("4. Set Savings Goal")
        print("5. Add Savings")
        print("6. Show Budget Summary")
        print("7. Save & Exit")
        choice = input("Choose an option: ").strip()
        try:
            if choice == '1':
                amount = float(input("Enter income amount: "))
                source = input("Enter income source: ")
                if amount <= 0 or not source.strip():
                    raise ValueError("Invalid input for income.")
                planner.add_income(amount, source)
            elif choice == '2':
                amount = float(input("Enter expense amount: "))
                category = input("Enter expense category: ")
                if amount <= 0 or not category.strip():
                    raise ValueError("Invalid input for expense.")
                planner.add_expense(amount, category)
            elif choice == '3':
                goal = float(input("Enter budget goal: "))
                if goal < 0:
                    raise ValueError("Budget goal cannot be negative.")
                planner.set_budget_goal(goal)
            elif choice == '4':
                goal = float(input("Enter savings goal: "))
                if goal < 0:
                    raise ValueError("Savings goal cannot be negative.")
                savings.set_savings_goal(goal)
            elif choice == '5':
                amount = float(input("Enter savings amount: "))
                if amount <= 0:
                    raise ValueError("Savings amount must be greater than zero.")
                savings.add_savings(amount)
            elif choice == '6':
                budget_summary = planner.get_budget_summary()
                print("\nBudget Summary:")
                print(planner.visualize_budget())
                savings_progress = savings.get_savings_progress()
                print(f"Savings Progress: {savings_progress['progress']:.2f}%")
            elif choice == '7':
                # Save data and exit
                data_handler.save_data(planner.export_budget_data())
                print("Data saved. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")
        except ValueError as e:
            print(f"Error: {e}")