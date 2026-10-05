def run_app():
    app = BudgetTrackerPro()
    app.add_user("john_doe", "password123")  # Example user
    app.login("john_doe", "password123")
    while True:
        main_menu()
        choice = input("Choose an option: ")
        if choice == "1":
            amount = float(input("Enter income amount: "))
            source = input("Enter income source: ")
            app.current_user.income.add_income(amount, source)
            print("Income added.")
        elif choice == "2":
            amount = float(input("Enter expense amount: "))
            category = input("Enter expense category: ")
            app.current_user.expense.add_expense(amount, category)
            print("Expense added.")
        elif choice == "3":
            goal_amount = float(input("Enter goal amount: "))
            name = input("Enter goal name: ")
            description = input("Enter goal description: ")
            app.current_user.budget_goal.set_goal(goal_amount, name, description)
        elif choice == "4":
            app.current_user.budget_goal.check_goal()
        elif choice == "5":
            date = input("Enter reminder date: ")
            description = input("Enter reminder description: ")
            app.current_user.reminder.add_reminder(date, description)
            print("Reminder added.")
        elif choice == "6":
            data = {
                "Income": app.current_user.income.get_total_income(),
                "Expense": app.current_user.expense.get_total_expense()
            }
            app.current_user.visualization.generate_pie_chart(data)
        elif choice == "7":
            app.logout()
            break
        elif choice == "0":
            print("Exiting application.")
            break
        else:
            print("Invalid choice. Please try again.")