def get_user_input(self):
        '''
        Captures input from the user.
        '''
        while True:
            user_input = input(self.prompt_message).strip()
            if self.validate_input(user_input):
                return user_input
            else:
                print(self.invalid_input_message)