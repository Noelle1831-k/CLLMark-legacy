def can_form_word(self, word, available_letters):
        '''
        Checks if a word can be formed from the available letters.
        :param word: The word to check.
        :param available_letters: The string of available letters.
        :return: True if the word can be formed from the letters, otherwise False.
        '''
        word_counter = Counter(word)
        available_counter = Counter(available_letters)
        # Iterate over each letter in the word and check against available letters
        for letter, count in word_counter.items():
            if available_counter[letter] < count:
                return False
        return True