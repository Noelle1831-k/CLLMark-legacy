def start_tour(self):
        '''
        Initiates a virtual tour.
        '''
        print("Starting a virtual tour...")
        for ecosystem in self.ecosystems:
            self.display_ecosystem(ecosystem)