def get_preference(self, key):
        '''
        Retrieves a specific preference value by key.
        '''
        return self.preferences.get(key, None)