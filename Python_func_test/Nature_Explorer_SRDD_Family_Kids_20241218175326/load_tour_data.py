def load_tour_data(self):
        '''
        Loads data for each ecosystem.
        '''
        print("Loading tour data...")
        for ecosystem in self.ecosystems:
            self.tour_data[ecosystem] = self.retrieve_ecosystem_data(ecosystem)
        print("Tour data loaded.")