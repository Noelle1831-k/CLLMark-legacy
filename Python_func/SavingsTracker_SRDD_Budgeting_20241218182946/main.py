def main():
    file_handler = FileHandler('data.json')
    data = file_handler.load_data()
    tracker = SavingsTracker(data)
    while True:
        print("1. Add User")
        print("2. Add Income")
        print("3. Add Expense")
        print("4. Set Savings Target")
        print("5. Generate Report")
        print("6. Visualize Savings")
        print("7. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            name = input("Enter user name: ")
            tracker.add_user(name)
        elif choice == '2':
            name = input("Enter user name: ")
            amount = float(input("Enter income amount: "))
            category = input("Enter category: ")
            tracker.get_user(name).add_income(amount, category)
        elif choice == '3':
            name = input("Enter user name: ")
            amount = float(input("Enter expense amount: "))
            category = input("Enter category: ")
            tracker.get_user(name).add_expense(amount, category)
        elif choice == '4':
            name = input("Enter user name: ")
            target = float(input("Enter savings target: "))
            tracker.get_user(name).set_savings_target(target)
        elif choice == '5':
            name = input("Enter user name: ")
            report = tracker.generate_report(name)
            print(report)
        elif choice == '6':
            name = input("Enter user name: ")
            tracker.visualize_savings(name)
        elif choice == '7':
            file_handler.save_data(tracker.users)
            break
        else:
            print("Invalid choice. Please try again.")