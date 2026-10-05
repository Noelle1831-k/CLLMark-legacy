def read_file(self, file):
        '''
        Reads the content of a file and returns it as a string.
        '''
        try:
            with open(file, 'r', encoding='utf-8') as f:
                content = f.read()
            return content
        except FileNotFoundError:
            print(f"Error: The file {file} was not found.")
            return ""
        except IOError:
            print(f"Error: An error occurred while reading the file {file}.")
            return ""