def run(self):
        while True:
            print("\nBudgetTrackerLite")
            print("1. Add Income")
            print("2. Add Expense")
            print("3. Set Goal")
            print("4. View Budget Summary")
            print("5. Visualize Budget Breakdown")
            print("6. Visualize Goals")
            print("7. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                source = input("Enter income source: ")
                while True:
                    try:
                        amount = float(input("Enter income amount: "))
                        break
                    except ValueError:
                        print("Invalid input. Please enter a numeric value for the amount.")
                self.budget_manager.add_income(source, amount)
            elif choice == '2':
                category = input("Enter expense category: ")
                while True:
                    try:
                        amount = float(input("Enter expense amount: "))
                        break
                    except ValueError:
                        print("Invalid input. Please enter a numeric value for the amount.")
                self.budget_manager.add_expense(category, amount)
            elif choice == '3':
                category = input("Enter goal category: ")
                while True:
                    try:
                        amount = float(input("Enter goal amount: "))
                        break
                    except ValueError:
                        print("Invalid input. Please enter a numeric value for the amount.")
                self.budget_manager.set_goal(category, amount)
            elif choice == '4':
                summary = self.budget_manager.get_budget_summary()
                print("\nBudget Summary")
                print(f"Total Income: {summary['total_income']}")
                print(f"Total Expenses: {summary['total_expenses']}")
                print(f"Remaining Budget: {summary['remaining_budget']}")
                print("Goals:")
                for category, amount in summary['goals'].items():
                    print(f"{category}: {amount}")
            elif choice == '5':
                summary = self.budget_manager.get_budget_summary()
                self.visualization.plot_budget_breakdown(summary)
            elif choice == '6':
                goals = self.budget_manager.goals
                self.visualization.plot_goals(goals)
            elif choice == '7':
                print("Exiting BudgetTrackerLite.")
                break
            else:
                print("Invalid choice. Please try again.")