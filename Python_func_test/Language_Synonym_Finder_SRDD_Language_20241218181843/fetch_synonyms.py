def fetch_synonyms(self, word):
        '''
        Fetches synonyms for a given word.
        '''
        return self.synonyms_database.get(word, [])