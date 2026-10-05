def identify_errors(self, parsed_text):
        '''
        Identify grammatical errors in the parsed text.
        '''
        errors = []
        for component in parsed_text:
            if not self.is_grammatically_correct(component):
                errors.append(component)
        return errors