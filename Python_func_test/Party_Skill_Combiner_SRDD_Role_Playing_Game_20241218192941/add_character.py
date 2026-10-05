def add_character(self, character):
        '''
        Add a character to the party.
        '''
        if isinstance(character, Character):
            self.characters.append(character)