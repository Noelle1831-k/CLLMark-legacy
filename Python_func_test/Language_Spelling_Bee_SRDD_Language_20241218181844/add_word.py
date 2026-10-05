def add_word(self, language, difficulty, word):
        '''
        Adds a new word to the database.
        '''
        if language not in self.words:
            self.words[language] = {}
        if difficulty not in self.words[language]:
            self.words[language][difficulty] = list()
        self.words[language][difficulty].append(word)