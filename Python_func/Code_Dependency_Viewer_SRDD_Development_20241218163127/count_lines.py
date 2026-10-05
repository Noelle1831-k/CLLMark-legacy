def count_lines(self, file):
        '''
        Counts the number of lines in a file.
        '''
        content = self.read_file(file)
        return len(content.splitlines())