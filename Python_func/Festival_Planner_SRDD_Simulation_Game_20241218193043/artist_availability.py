def artist_availability(self):
        '''
        Randomly determines if the artist is available for the festival.
        '''
        self.available = choice([True, False])
        return self.available