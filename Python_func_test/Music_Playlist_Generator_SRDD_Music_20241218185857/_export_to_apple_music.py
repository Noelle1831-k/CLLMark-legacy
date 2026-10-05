def _export_to_apple_music(self, playlist):
        '''
        Simulates exporting the playlist to Apple Music.
        '''
        print("Exporting to Apple Music...")
        for track in playlist:
            print(f"Adding {track['title']} to Apple Music playlist.")