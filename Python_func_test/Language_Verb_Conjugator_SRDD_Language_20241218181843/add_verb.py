def add_verb(self, base_form, conjugations):
        '''
        Adds a verb to the database.
        '''
        verb = Verb(base_form, conjugations)
        self.verbs[base_form] = verb