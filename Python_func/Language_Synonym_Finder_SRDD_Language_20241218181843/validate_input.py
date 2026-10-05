def validate_input(self, word):
        '''
        Validates user input.
        '''
        return bool(word and word.isalpha())