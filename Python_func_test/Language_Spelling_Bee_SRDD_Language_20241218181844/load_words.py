def load_words(self):
        '''
        Loads additional words from a JSON file or database.
        '''
        try:
            with open('additional_words.json', 'r') as file:
                additional_words = json.load(file)
                for language, levels in additional_words.items():
                    if language not in self.words:
                        self.words[language] = {}
                    for level, words in levels.items():
                        if level not in self.words[language]:
                            self.words[language][level] = []
                        self.words[language][level].extend(words)
        except FileNotFoundError:
            print("No additional words file found. Using default words.")