def display_menu(self):
        while True:
            print("\nFinance Expense Organizer")
            print("1. Add Expense")
            print("2. Add Category")
            print("3. View Expenses by Category")
            print("4. View Total Expenses")
            print("5. List All Categories")
            print("6. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_expense()
            elif choice == '2':
                self.add_category()
            elif choice == '3':
                self.view_expenses()
            elif choice == '4':
                self.view_total_expenses()
            elif choice == '5':
                self.list_all_categories()
            elif choice == '6':
                print("Exiting the application. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")