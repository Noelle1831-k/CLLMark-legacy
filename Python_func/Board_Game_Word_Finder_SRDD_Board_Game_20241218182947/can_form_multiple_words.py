def can_form_multiple_words(self, words, available_letters):
        '''
        Checks if multiple words can be formed from the available letters.
        :param words: A list of words to check.
        :param available_letters: The string of available letters.
        :return: A list of words that can be formed.
        '''
        valid_words = []
        available_counter = Counter(available_letters)
        for word in words:
            word_counter = Counter(word)
            if all(available_counter[letter] >= count for letter, count in word_counter.items()):
                valid_words.append(word)
        return valid_words