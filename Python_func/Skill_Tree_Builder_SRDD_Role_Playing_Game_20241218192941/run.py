def run(self):
        '''
        Runs the main application loop to process user inputs.
        '''
        while True:
            self.display_menu()
            choice = input("Enter your choice: ").strip()
            self.process_input(choice)