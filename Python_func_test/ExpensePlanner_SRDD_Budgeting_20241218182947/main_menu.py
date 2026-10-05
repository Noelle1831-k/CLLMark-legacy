def main_menu(self):
        while True:
            print("\nMain Menu:")
            print("1. Create User")
            print("2. Add Expense")
            print("3. Set Budget Goal")
            print("4. Generate Report")
            print("5. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.create_user()
            elif choice == '2':
                self.add_expense()
            elif choice == '3':
                self.set_budget_goal()
            elif choice == '4':
                self.generate_report()
            elif choice == '5':
                print("Thank you for using ExpensePlanner!")
                break
            else:
                print("Invalid choice. Please try again.")