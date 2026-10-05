def get_weaknesses(self):
        '''
        Returns the weaknesses of the class.
        '''
        return [ability for ability in self.abilities if ability['type'] == 'weakness']