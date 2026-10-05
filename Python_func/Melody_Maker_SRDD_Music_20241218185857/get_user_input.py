def get_user_input(self, prompt=""):
        '''
        Prompts the user for input and returns the user's response.
        Parameters:
        prompt (str): The message displayed to the user when asking for input.
        Returns:
        str: The user's input.
        '''
        user_input = input(prompt)
        return user_input