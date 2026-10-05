def write_file(self, content):
        '''
        Writes content to the file.
        '''
        with open(self.file_path, 'w') as file:
            file.write(content)