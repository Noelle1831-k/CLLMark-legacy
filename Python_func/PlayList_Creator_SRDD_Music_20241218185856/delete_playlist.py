def delete_playlist(self, name):
        '''
        Deletes a playlist by name.
        '''
        if name in self.playlists:
            del self.playlists[name]