def run(self):
        """
        Runs the main menu loop for the application.
        """
        while True:
            self.display_menu()
            choice = input("Select an option: ").strip()
            try:
                if choice == "1":
                    self.add_income()
                elif choice == "2":
                    self.add_expense()
                elif choice == "3":
                    self.set_savings_target()
                elif choice == "4":
                    self.view_progress()
                elif choice == "5":
                    self.generate_report()
                elif choice == "6":
                    print("Exiting application. Goodbye!")
                    break
                else:
                    print("Invalid choice. Please try again.")
            except ValueError as ve:
                print(f"Input error: {ve}")
            except Exception as e:
                print(f"An unexpected error occurred: {e}")