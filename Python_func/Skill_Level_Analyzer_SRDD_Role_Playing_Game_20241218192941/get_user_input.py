def get_user_input(self):
        '''
        Collects input from the user for skill parameters.
        '''
        attributes = self._get_valid_input("Enter the required attributes for the skill: ")
        complexity = self._get_valid_input("Enter the complexity of the skill: ")
        progression = self._get_valid_input("Enter the skill progression rate: ")
        return attributes, complexity, progression