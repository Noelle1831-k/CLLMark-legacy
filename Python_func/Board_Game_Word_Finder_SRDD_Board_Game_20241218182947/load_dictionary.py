def load_dictionary(self):
        '''
        Loads the dictionary of valid words from a file.
        The dictionary is stored as a set for fast lookups.
        '''
        dictionary_file = "dictionary.txt"
        if not os.path.exists(dictionary_file):
            raise FileNotFoundError(f"Dictionary file '{dictionary_file}' not found.")
        with open(dictionary_file, 'r') as file:
            for line in file:
                word = line.strip().lower()
                self.words_set.add(word)