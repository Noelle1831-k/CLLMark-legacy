def load_data(self):
        '''
        Loads budget data from a file.
        If the file does not exist or contains invalid data, returns an empty dictionary.
        '''
        if not os.path.exists(self.FILE_NAME):
            print(f'{self.FILE_NAME} not found. Creating a new file.')
            return {}
        try:
            with open(self.FILE_NAME, 'r') as file:
                return json.load(file)
        except (json.JSONDecodeError, ValueError):
            print(f'Error reading {self.FILE_NAME}. Data may be corrupted.')
            return {}