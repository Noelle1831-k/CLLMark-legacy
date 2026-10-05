def view_events(self):
        '''
        Display the list of events.
        '''
        print('\nEvents:', end='\n')
        for event in self.data_store.get_events():
            print(event, end='\n')