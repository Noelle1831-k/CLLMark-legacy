def load_data(self):
        '''
        Load user data from a file.
        '''
        try:
            with open(self.filename, 'r') as file:
                data = json.load(file)
                return data
        except FileNotFoundError:
            return None