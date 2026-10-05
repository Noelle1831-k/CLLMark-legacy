def handle_user_input(self, choice):
        if choice == '1':
            name = input("Enter expense name: ")
            amount_input = input("Enter amount: ")
            amount = validate_input(amount_input, 'float')
            if amount is None:
                print("Invalid amount. Please enter a valid number.")
                return
            category = input("Enter category: ")
            self.expense_tracker.add_expense(name, amount, category)
            self.data_storage.save_data(self.expense_tracker.get_expenses())
        elif choice == '2':
            name = input("Enter expense name to remove: ")
            self.expense_tracker.remove_expense(name)
            self.data_storage.save_data(self.expense_tracker.get_expenses())
        elif choice == '3':
            expenses = self.expense_tracker.get_expenses()
            if not expenses:
                print("No expenses recorded.")
            else:
                for expense in expenses:
                    print(f"Name: {expense['name']}, Amount: {expense['amount']}, Category: {expense['category']}")
        elif choice == '4':
            recommendations = self.recommendation_engine.get_recommendations()
            if not recommendations:
                print("No recommendations at this time.")
            else:
                for recommendation in recommendations:
                    print(recommendation)
        elif choice == '5':
            print("Exiting the application. Goodbye!")
            exit()
        else:
            print("Invalid choice. Please try again.")