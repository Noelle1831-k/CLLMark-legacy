def save(self, filename):
        '''
        Saves the playlist to a file.
        '''
        with open(filename, 'w') as f:
            for song in self.songs:
                f.write(f"{song.file_path}\n")