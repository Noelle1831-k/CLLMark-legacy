def remove_word(self, language, difficulty, word):
        '''
        Removes a word from the database.
        '''
        try:
            self.words[language][difficulty].remove(word)
        except (KeyError, ValueError):
            print(f"Word '{word}' not found in {language} {difficulty} list.")