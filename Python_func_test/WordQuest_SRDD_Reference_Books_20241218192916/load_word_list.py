def load_word_list(self):
        '''
        Loads a word list from a file.
        '''
        try:
            with open('word_list.txt', 'r') as file:
                return [line.strip() for line in file]
        except FileNotFoundError:
            return ["example", "vocabulary", "language", "quiz", "puzzle"]