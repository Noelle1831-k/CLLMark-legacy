def get_playlist_details(self):
        '''
        Returns the details of the playlist.
        '''
        return {"name": self.name, "songs": [song.get_details() for song in self.songs]}