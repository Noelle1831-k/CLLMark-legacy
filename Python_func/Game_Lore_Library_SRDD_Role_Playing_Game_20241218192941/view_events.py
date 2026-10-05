def view_events(self):
        '''
        Display the list of events.
        '''
        print("\nEvents:")
        for event in self.data_store.get_events():
            print(event)