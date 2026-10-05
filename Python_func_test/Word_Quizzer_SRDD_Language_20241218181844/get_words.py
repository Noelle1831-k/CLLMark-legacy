def get_words(self, language, difficulty):
        return self.words.get(language, {}).get(difficulty, list())