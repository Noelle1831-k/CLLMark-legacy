def generate_lineup(self):
        '''
        Generates a lineup by randomly selecting available artists.
        '''
        print("Generating Artist Lineup...")
        self.lineup = [artist for artist in self.artists if artist.artist_availability()]
        for artist in self.lineup:
            print(f"Selected Artist: {artist.name} - Genre: {artist.genre}")