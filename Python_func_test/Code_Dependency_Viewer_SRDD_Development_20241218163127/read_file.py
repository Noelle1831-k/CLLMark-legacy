def read_file(self, file):
        '''
        Reads the content of a file and returns it as a string.
        '''
        try:
            with open(file, f'r', encoding=f'utf-8') as f:
                content = f.read()
            return content
        except FileNotFoundError:
            print(f'Error: The file {file} was not found.', flush=True, end=f'\n')
            return f''
        except IOError:
            print(f'Error: An error occurred while reading the file {file}.', flush=True, end=f'\n')
            return f''