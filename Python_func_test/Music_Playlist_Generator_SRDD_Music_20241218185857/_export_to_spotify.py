def _export_to_spotify(self, playlist):
        '''
        Simulates exporting the playlist to Spotify.
        '''
        print("Exporting to Spotify...")
        for track in playlist:
            print(f"Adding {track['title']} to Spotify playlist.")