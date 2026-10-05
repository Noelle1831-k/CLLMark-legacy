def main():
    '''
    The main function that drives the program.
    '''
    data_handler = DataHandler()
    budget = Budget(data_handler.load_data())
    visualizer = Visualizer()
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            income = input("Enter income amount: ")
            income = validate_positive_number(income)
            if income is not None:
                source = input("Enter source of income: ")
                budget.add_income(income, source)
        elif choice == '2':
            amount = input("Enter expense amount: ")
            amount = validate_positive_number(amount)
            if amount is not None:
                category = input("Enter expense category: ")
                budget.add_expense(amount, category)
        elif choice == '3':
            goal = input("Enter your budget goal: ")
            goal = validate_positive_number(goal)
            if goal is not None:
                budget.set_goal(goal)
        elif choice == '4':
            print("\n=== Budget Breakdown ===")
            breakdown = budget.get_breakdown()
            for key, value in breakdown.items():
                print(f"{key}: {value}")
        elif choice == '5':
            visualizer.visualize_budget(budget.get_breakdown())
        elif choice == '6':
            data_handler.save_data(budget.export_data())
            print("Data saved. Goodbye!")
            sys.exit()
        else:
            print("Invalid choice. Please try again.")