def view_characters(self):
        '''
        Display the list of characters.
        '''
        print("\nCharacters:")
        for character in self.data_store.get_characters():
            print(character)