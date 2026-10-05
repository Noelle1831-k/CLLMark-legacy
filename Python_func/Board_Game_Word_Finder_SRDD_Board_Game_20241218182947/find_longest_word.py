def find_longest_word(self, words):
        '''
        Finds the longest word from a list of words.
        :param words: A list of words.
        :return: The longest word in the list.
        '''
        return max(words, key=len) if words else None