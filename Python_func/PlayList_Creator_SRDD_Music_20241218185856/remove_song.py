def remove_song(self, song_title):
        '''
        Removes a song from the playlist by title.
        '''
        self.songs = [song for song in self.songs if song.title != song_title]