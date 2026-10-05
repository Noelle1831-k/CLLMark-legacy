def _get_valid_input(self, prompt):
        '''
        Helper function to get validated input from the user.
        '''
        while True:
            value = input(prompt)
            validated_value = validate_input(value)
            if validated_value is not None:
                return validated_value