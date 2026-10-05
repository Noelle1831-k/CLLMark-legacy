def run(self):
        self.ui.display_menu()
        while True:
            choice = self.ui.get_user_input("Select an option: ")
            if choice == '1':
                income = self.ui.get_user_input("Enter income: ")
                try:
                    self.expense_manager.add_income(income)
                    self.ui.display_success("Income added successfully.")
                except ValueError as e:
                    self.ui.display_error(str(e))
            elif choice == '2':
                expense = self.ui.get_user_input("Enter expense: ")
                category = self.ui.get_user_input("Enter category: ")
                try:
                    self.expense_manager.add_expense(expense, category)
                    self.ui.display_success("Expense added successfully.")
                except ValueError as e:
                    self.ui.display_error(str(e))
            elif choice == '3':
                report = self.expense_manager.generate_report()
                self.ui.show_report(report)
                if self.ui.confirm_action("generate a detailed chart"):
                    categorized_data = self.expense_manager.categorize_expense()
                    self.report_generator.generate_chart(categorized_data)
                    self.report_generator.generate_pie_chart(categorized_data)
                    self.report_generator.generate_line_chart(categorized_data)
            elif choice == '4':
                if self.ui.confirm_action("save data"):
                    try:
                        self.data_storage.save_data(self.expense_manager.get_data())
                        self.ui.display_success("Data saved successfully.")
                    except IOError as e:
                        self.ui.display_error(str(e))
            elif choice == '5':
                if self.ui.confirm_action("load data"):
                    try:
                        self.expense_manager.set_data(self.data_storage.load_data())
                        self.ui.display_success("Data loaded successfully.")
                    except (FileNotFoundError, ValueError) as e:
                        self.ui.display_error(str(e))
            elif choice == '6':
                if self.ui.confirm_action("exit the application"):
                    break
            else:
                self.ui.display_error("Invalid choice. Please select a valid option.")