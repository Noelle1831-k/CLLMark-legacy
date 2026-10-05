def create_playlist(self, songs):
        '''
        Creates a new playlist with the given songs.
        '''
        for song in songs:
            self.playlist.add_song(song)