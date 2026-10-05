def find_words(self, letters):
        '''
        Finds all valid words that can be formed from the given set of letters.
        :param letters: A string of available letters.
        :return: A set of valid words formed from the letters.
        '''
        valid_words = set()
        # Generate all possible word lengths from 2 to the length of the letters string
        for length in range(2, len(letters) + 1):
            permutations = itertools.permutations(letters, length)
            for perm in permutations:
                word = ''.join(perm)
                # Check if the word is valid
                if self.word_validator.can_form_word(word, letters) and self.dictionary_manager.is_word_in_dictionary(word):
                    valid_words.add(word)
        return valid_words