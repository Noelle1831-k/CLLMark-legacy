def view_locations(self):
        '''
        Display the list of locations.
        '''
        print("\nLocations:")
        for location in self.data_store.get_locations():
            print(location)