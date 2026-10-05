def add_song_to_playlist(self):
        '''
        Handles adding a song to a playlist.
        '''
        playlist_name = input("Enter playlist name: ")
        playlist = self.manager.get_playlist(playlist_name)
        if playlist:
            title = input("Enter song title: ")
            artist = input("Enter song artist: ")
            duration = input("Enter song duration (mins): ")
            song = Song(title, artist, duration)
            playlist.add_song(song)
            print(f"Song '{title}' added to playlist '{playlist_name}'.")
        else:
            print(f"Playlist '{playlist_name}' not found.")