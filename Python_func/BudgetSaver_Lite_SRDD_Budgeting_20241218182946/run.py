def run(self):
        self.storage.load_data(self.manager)
        while self.running:
            choice = self.ui.display_menu()
            if choice == '1':
                self.manager.add_income(self.ui.get_user_input("Enter income amount: "))
            elif choice == '2':
                self.manager.add_expense(self.ui.get_user_input("Enter expense amount: "))
            elif choice == '3':
                self.manager.set_goal(self.ui.get_user_input("Enter budget goal: "))
            elif choice == '4':
                self.visualizer.show_pie_chart(self.manager.expenses)
            elif choice == '5':
                self.visualizer.show_bar_chart(self.manager.income, self.manager.expenses)
            elif choice == '6':
                self.storage.save_data(self.manager)
                self.running = False
            else:
                self.ui.display_message("Invalid choice. Please try again.")