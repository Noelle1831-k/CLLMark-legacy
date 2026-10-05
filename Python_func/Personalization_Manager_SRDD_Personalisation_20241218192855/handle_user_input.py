def handle_user_input(self):
        '''
        Handles user input and executes the corresponding command.
        '''
        user_input = input("\nEnter your choice: ").strip()
        command = self.commands.get(user_input, None)
        if command:
            command()
        else:
            print("Invalid choice. Please try again.")