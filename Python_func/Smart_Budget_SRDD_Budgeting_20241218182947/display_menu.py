def display_menu(self):
        while True:
            print("\nSmartBudget Menu:")
            print("1. Add Income")
            print("2. Add Expense")
            print("3. View Balance")
            print("4. Get Spending Recommendations")
            print("5. Save Data")
            print("6. Load Data")
            print("7. View Expense Report")
            print("8. Exit")
            choice = input("Select an option: ")
            self.process_user_input(choice)