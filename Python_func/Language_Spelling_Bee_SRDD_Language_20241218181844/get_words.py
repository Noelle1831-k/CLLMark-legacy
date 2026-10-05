def get_words(self, language, difficulty):
        '''
        Retrieves words based on the selected language and difficulty.
        '''
        return self.words.get(language, {}).get(difficulty, [])