def __eq__(self, other):
        '''
        Compares two skills based on their attributes.
        '''
        if isinstance(other, Skill):
            return (self.name == other.name and
                    self.description == other.description and
                    self.level == other.level)
        return False