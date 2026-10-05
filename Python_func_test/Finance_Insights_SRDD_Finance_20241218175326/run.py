def run(self):
        '''
        Run the main loop of the user interface.
        '''
        user = User(user_id=1, name='John Doe', email='john.doe@example.com')
        while True:
            self.display_menu()
            choice = self.get_user_choice()
            if choice == 1:
                self.add_income(user)
            elif choice == 2:
                self.add_expense(user)
            elif choice == 3:
                self.view_financial_report(user)
            elif choice == 4:
                self.view_visualizations(user)
            elif choice == 5:
                self.get_financial_suggestions(user)
            elif choice == 6:
                print("Thank you for using Finance Insights. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")