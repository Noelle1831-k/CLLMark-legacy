def add_song(self, song):
        '''
        Adds a song to the playlist.
        '''
        if isinstance(song, Song):
            self.songs.append(song)