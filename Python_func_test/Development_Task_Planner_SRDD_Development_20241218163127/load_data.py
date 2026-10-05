def load_data(self, filename):
        '''
        Loads data from a JSON file.
        Parameters:
        - filename: The name of the file to load data from.
        '''
        try:
            with open(filename, "r") as file:
                return json.load(file)
        except FileNotFoundError:
            return list()