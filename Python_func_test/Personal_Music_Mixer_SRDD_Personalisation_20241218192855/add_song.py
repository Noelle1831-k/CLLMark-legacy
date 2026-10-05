def add_song(self, song_path):
        '''
        Adds a song to the playlist.
        '''
        song = AudioFile(song_path)
        self.songs.append(song)