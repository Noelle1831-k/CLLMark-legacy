def display_party(self):
        '''
        Display all characters currently in the party.
        '''
        if not self.characters:
            print("The party is currently empty.")
        else:
            for character in self.characters:
                print(character)