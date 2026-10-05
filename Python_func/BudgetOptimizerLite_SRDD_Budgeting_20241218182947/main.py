def main():
    budget_optimizer = BudgetOptimizer()
    user_interface = UserInterface(budget_optimizer)
    data_visualizer = DataVisualizer()
    file_manager = FileManager()
    print("Welcome to BudgetOptimizerLite!\n")
    while True:
        user_interface.display_menu()
        choice = user_interface.get_user_input("Enter your choice: ")
        if choice == '1':
            amount = user_interface.get_valid_number("Enter income amount: ")
            source = user_interface.get_user_input("Enter income source: ")
            budget_optimizer.add_income(amount, source)
        elif choice == '2':
            amount = user_interface.get_valid_number("Enter expense amount: ")
            category = user_interface.get_user_input("Enter expense category: ")
            budget_optimizer.add_expense(amount, category)
        elif choice == '3':
            amount = user_interface.get_valid_number("Enter goal amount: ")
            description = user_interface.get_user_input("Enter goal description: ")
            budget_optimizer.set_goal(amount, description)
        elif choice == '4':
            user_interface.show_budget_summary()
        elif choice == '5':
            data_visualizer.plot_budget_breakdown(budget_optimizer.income, budget_optimizer.expenses)
        elif choice == '6':
            file_manager.save_to_file(budget_optimizer.get_data(), "budget_data.txt")
        elif choice == '7':
            budget_optimizer.load_data(file_manager.load_from_file("budget_data.txt"))
        elif choice == '8':
            print("Thank you for using BudgetOptimizerLite. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")