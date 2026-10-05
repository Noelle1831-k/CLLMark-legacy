def get_idiom(self, word, language, difficulty):
        return self.idioms.get(language, {}).get(word, "unknown")