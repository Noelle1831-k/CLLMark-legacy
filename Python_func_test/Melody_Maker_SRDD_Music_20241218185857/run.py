def run(self):
        '''
        Runs the application, displaying the main menu and processing user inputs in a loop.
        '''
        self.ui.display_message("Welcome to Melody Maker!")
        while True:
            self.ui.display_menu()
            choice = self.ui.get_user_input("Enter your choice: ")
            if choice == '1':
                self.create_melody()
            elif choice == '2':
                self.edit_melody()
            elif choice == '3':
                self.select_instrument()
            elif choice == '4':
                self.select_style()
            elif choice == '5':
                self.ui.display_message("Exiting Melody Maker. Goodbye!")
                break
            else:
                self.ui.display_error("Invalid choice. Please try again.")