def add_word(self, word):
        '''
        Adds a word to the dictionary set. Used for dynamically adding words.
        :param word: The word to add.
        '''
        self.words_set.add(word.lower())