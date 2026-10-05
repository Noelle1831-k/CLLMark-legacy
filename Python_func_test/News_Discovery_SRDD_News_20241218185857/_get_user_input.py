def _get_user_input(self, prompt):
        '''
        Helper method to get and process user input.
        '''
        user_input = input(prompt)
        return [item.strip() for item in user_input.split(',') if item.strip()]