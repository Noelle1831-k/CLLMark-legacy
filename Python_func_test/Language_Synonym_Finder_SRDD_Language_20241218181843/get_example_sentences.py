def get_example_sentences(self, word):
        '''
        Provides example sentences for a word.
        '''
        return self.examples_database.get(word, ["No example sentences available."])