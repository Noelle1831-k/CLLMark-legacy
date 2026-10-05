def ask_continue(self):
        '''
        Asks the user if they wish to continue.
        This method ensures that the user provides a valid response (either 'y' or 'n').
        :return: True if the user wants to continue, otherwise False.
        '''
        while True:
            response = input("Do you want to try again? (y/n): ").strip().lower()
            if response not in ['y', 'n']:
                print("Invalid response. Please enter 'y' for yes or 'n' for no.")
                continue
            return response == 'y'