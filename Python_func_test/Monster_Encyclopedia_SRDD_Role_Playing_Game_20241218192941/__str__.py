def __str__(self):
        '''
        Return a string representation of the database.
        '''
        return '\n'.join(str(monster) for monster in self.monsters)