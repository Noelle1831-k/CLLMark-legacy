def get_synonym(self, word, language, difficulty):
        return self.synonyms.get(language, {}).get(word, "unknown")