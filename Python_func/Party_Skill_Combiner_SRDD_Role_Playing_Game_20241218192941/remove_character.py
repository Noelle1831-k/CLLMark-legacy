def remove_character(self, character_name):
        '''
        Remove a character from the party by name.
        '''
        self.characters = [c for c in self.characters if c.name != character_name]