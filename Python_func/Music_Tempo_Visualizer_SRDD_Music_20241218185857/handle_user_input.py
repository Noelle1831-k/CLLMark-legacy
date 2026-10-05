def handle_user_input(self):
        '''
        Handles additional user interactions after visualization.
        '''
        print("Handling user interactions...")
        while True:
            command = input("Type 'exit' to quit or 'help' for options: ").strip().lower()
            if command == 'exit':
                print("Exiting application. Thank you!")
                break
            elif command == 'help':
                print("Options: 'exit' - Quit application | 'help' - Show options")
            else:
                print("Invalid command. Type 'help' for available options.")