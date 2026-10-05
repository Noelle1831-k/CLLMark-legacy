def is_anagram(self, word1, word2):
        '''
        Checks if two words are anagrams of each other.
        :param word1: The first word.
        :param word2: The second word.
        :return: True if the words are anagrams, otherwise False.
        '''
        return Counter(word1) == Counter(word2)