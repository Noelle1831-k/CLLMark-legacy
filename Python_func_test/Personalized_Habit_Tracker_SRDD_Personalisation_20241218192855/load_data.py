def load_data(self):
        '''
        Load data from a file.
        '''
        try:
            with open(self.filename, 'r') as file:
                return json.load(file)
        except FileNotFoundError:
            return {}