def search_verb(self, base_form):
        '''
        Allows the user to search for a verb.
        '''
        verb = self.database.get_verb(base_form)
        if verb:
            self.display_conjugation(verb)
        else:
            print(f'Verb "{base_form}" not found in the database.', flush=True, end='\n')