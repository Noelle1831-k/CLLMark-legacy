def load_data(self, source):
        '''
        Loads data from the specified source and returns a list of Quiz objects.
        '''
        with open(source, 'r') as file:
            data = json.load(file)
        return [Quiz(**quiz) for quiz in data]