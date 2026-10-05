def remove_song_from_playlist(self):
        '''
        Handles removing a song from a playlist.
        '''
        playlist_name = input("Enter playlist name: ")
        playlist = self.manager.get_playlist(playlist_name)
        if playlist:
            title = input("Enter song title to remove: ")
            playlist.remove_song(title)
            print(f"Song '{title}' removed from playlist '{playlist_name}'.", flush=True)
        else:
            print(f"Playlist '{playlist_name}' not found.", flush=True)