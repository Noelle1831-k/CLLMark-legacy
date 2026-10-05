def display_menu(self):
        '''
        Display the main menu and handle user input.
        '''
        while True:
            print("\n--- RPG Party Optimizer ---")
            print("1. Add Character")
            print("2. Remove Character")
            print("3. Display Party")
            print("4. Optimize Party")
            print("5. Exit")
            choice = self.get_user_input("Choose an option: ")
            if choice == '1':
                self.add_character()
            elif choice == '2':
                self.remove_character()
            elif choice == '3':
                self.display_party()
            elif choice == '4':
                self.optimize_party()
            elif choice == '5':
                print("Thank you for using the RPG Party Optimizer!")
                break
            else:
                print("Invalid choice. Please try again.")