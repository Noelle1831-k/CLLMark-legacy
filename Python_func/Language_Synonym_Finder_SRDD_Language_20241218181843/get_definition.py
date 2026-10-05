def get_definition(self, word):
        '''
        Retrieves the definition of a word.
        '''
        return self.definitions_database.get(word, 'Definition not found.')