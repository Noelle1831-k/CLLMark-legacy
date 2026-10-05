def _check_capitalization(self):
        '''
        Checks for capitalization errors, ensuring the first word is capitalized.
        '''
        words = self.sentence.strip().split()
        if words and not words[0][0].isupper():
            return ["Capitalization error: The first word of the sentence must be capitalized."]
        return []