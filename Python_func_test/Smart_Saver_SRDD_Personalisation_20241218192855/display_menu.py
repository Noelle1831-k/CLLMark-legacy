def display_menu(self):
        while True:
            print("\n--- Personal Finance Manager ---")
            print("1. Add Expense")
            print("2. Remove Expense")
            print("3. View Expenses")
            print("4. Get Recommendations")
            print("5. Exit")
            choice = input("Enter your choice: ")
            self.handle_user_input(choice)