def create_playlist(self, name):
        '''
        Creates a new playlist.
        '''
        if name not in self.playlists:
            self.playlists[name] = Playlist(name)