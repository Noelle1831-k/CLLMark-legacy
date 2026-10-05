def main():
    ui = UserInterface()
    user = User()
    data_storage = DataStorage()
    while True:
        ui.display_menu()
        choice = ui.get_user_input()
        if choice == '1':
            user.add_income()
        elif choice == '2':
            user.add_expense()
        elif choice == '3':
            user.set_budget_goal()
        elif choice == '4':
            analyzer = BudgetAnalyzer(user)
            analyzer.analyze_spending()
            analyzer.provide_recommendations()
        elif choice == '5':
            data_storage.save_data(user)
        elif choice == '6':
            user = data_storage.load_data()
        elif choice == '7':
            print("Exiting BudgetAssistant. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")