def process_user_input(self, choice):
        if choice == '1':
            amount = float(input("Enter income amount: "))
            self.user.add_income(amount)
        elif choice == '2':
            amount = float(input("Enter expense amount: "))
            category = input("Enter expense category: ")
            self.user.add_expense(amount, category)
        elif choice == '3':
            balance = self.user.get_balance()
            print(f"Current Balance: {balance}")
        elif choice == '4':
            recommendations = self.recommendation_engine.generate_recommendations(self.user)
            print("Spending Recommendations:")
            for rec in recommendations:
                print(rec)
        elif choice == '5':
            self.data_storage.save_data(self.user)
        elif choice == '6':
            self.user = self.data_storage.load_data()
        elif choice == '7':
            report = self.budget_manager.generate_expense_report(self.user)
            print("Expense Report:")
            print(report)
        elif choice == '8':
            print("Exiting SmartBudget. Goodbye!")
            sys.exit()
        else:
            print("Invalid choice. Please try again.")