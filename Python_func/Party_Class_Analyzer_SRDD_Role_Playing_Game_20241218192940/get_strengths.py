def get_strengths(self):
        '''
        Returns the strengths of the class.
        '''
        return [ability for ability in self.abilities if ability['type'] == 'strength']