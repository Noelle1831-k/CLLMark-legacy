def get_verb(self, base_form):
        '''
        Retrieves a verb from the database.
        '''
        return self.verbs.get(base_form, None)