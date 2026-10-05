def save_playlist(self, filename, songs):
        '''
        Saves a playlist to a file.
        '''
        with open(filename, 'w') as f:
            for song in songs:
                f.write(f"{song}\n")