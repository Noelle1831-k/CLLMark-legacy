def __hash__(self):
        '''
        Generates a hash value for the skill based on its attributes.
        '''
        return hash((self.name, self.description, self.level))