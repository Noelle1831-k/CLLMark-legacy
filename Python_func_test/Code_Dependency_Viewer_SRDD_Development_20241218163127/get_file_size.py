def get_file_size(self, file):
        '''
        Returns the size of the file in bytes.
        '''
        try:
            return os.path.getsize(file)
        except OSError:
            print(f"Error: Could not retrieve size for file {file}.")
            return 0