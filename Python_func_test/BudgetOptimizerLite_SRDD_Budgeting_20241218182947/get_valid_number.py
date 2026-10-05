def get_valid_number(self, prompt):
        '''
        Ensures that the user inputs a valid number (float).
        Arguments:
        prompt -- The string prompt to display to the user.
        Returns:
        valid_number -- The valid float input entered by the user.
        '''
        while True:
            try:
                user_input = self.get_user_input(prompt)
                valid_number = float(user_input)
                return valid_number
            except ValueError:
                print(f"Invalid input. '{user_input}' is not a valid number. Please enter a valid number.")