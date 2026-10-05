def load_playlist(self, filename):
        '''
        Loads a playlist from a file.
        '''
        with open(filename, 'r') as f:
            return [line.strip() for line in f.readlines()]