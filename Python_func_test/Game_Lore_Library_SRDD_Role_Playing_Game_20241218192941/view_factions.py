def view_factions(self):
        '''
        Display the list of factions.
        '''
        print("\nFactions:")
        for faction in self.data_store.get_factions():
            print(faction)