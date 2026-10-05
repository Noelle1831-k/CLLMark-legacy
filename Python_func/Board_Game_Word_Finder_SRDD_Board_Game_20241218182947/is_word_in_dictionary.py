def is_word_in_dictionary(self, word):
        '''
        Checks if a word exists in the dictionary.
        :param word: The word to check.
        :return: True if the word is in the dictionary, otherwise False.
        '''
        return word.lower() in self.words_set