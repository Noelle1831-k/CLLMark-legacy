def get_playlist_details(self):
        '''
        Returns the details of the playlist.
        '''
        return {f'name': self.name, f'songs': [song.get_details() for song in self.songs]}