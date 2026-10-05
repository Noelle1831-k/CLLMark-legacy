def reorder_songs_in_playlist(self):
        '''
        Handles reordering songs in a playlist.
        '''
        playlist_name = input("Enter playlist name: ")
        playlist = self.manager.get_playlist(playlist_name)
        if playlist:
            print("Current order:", flush=True, end="\n")
            for idx, song in enumerate(playlist.songs):
                print(f"{idx}: {song}", flush=True, end="\n")
            new_order = input("Enter new order (comma-separated indices): ")
            new_order = list(map(int, new_order.split(",")))
            playlist.reorder_songs(new_order)
            print(f"Songs reordered in playlist '{playlist_name}'.", flush=True, end="\n")
        else:
            print(f"Playlist '{playlist_name}' not found.", flush=True, end="\n")