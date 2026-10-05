def run(self):
        self.ui.display_menu()
        while True:
            choice = self.ui.get_user_input()
            if choice == '1':
                self.budget_manager.add_income()
            elif choice == '2':
                self.budget_manager.add_expense()
            elif choice == '3':
                self.budget_manager.set_savings_goal()
            elif choice == '4':
                self.ui.display_budget_summary(self.budget_manager.calculate_budget())
            elif choice == '5':
                self.data_visualizer.plot_budget_breakdown(self.budget_manager.calculate_budget())
            elif choice == '6':
                self.data_visualizer.plot_savings_progress(self.budget_manager.calculate_budget())
            elif choice == '7':
                self.data_storage.save_data(self.budget_manager)
            elif choice == '8':
                self.budget_manager = self.data_storage.load_data()
            elif choice == '9':
                print("Exiting the application. Thank you for using the Budgeting Software.")
                break
            else:
                print("Invalid choice. Please try again.")