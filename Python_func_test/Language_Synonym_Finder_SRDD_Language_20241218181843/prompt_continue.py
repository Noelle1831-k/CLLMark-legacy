def prompt_continue(self):
        '''
        Prompts the user to continue or exit.
        '''
        while True:
            response = input(self.continue_prompt).strip().lower()
            if response in ['y', 'n']:
                return response == 'y'
            else:
                print("Please enter 'y' or 'n'.")