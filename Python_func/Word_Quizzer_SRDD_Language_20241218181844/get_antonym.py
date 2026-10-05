def get_antonym(self, word, language, difficulty):
        return self.antonyms.get(language, {}).get(word, "unknown")