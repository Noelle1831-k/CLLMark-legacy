def read_file(self):
        '''
        Reads the file and returns its content.
        '''
        with open(self.file_path, 'r') as file:
            content = file.read()
        return content