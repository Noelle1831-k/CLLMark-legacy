def save_data(self, filename, data):
        '''
        Saves data to a JSON file.
        Parameters:
        - filename: The name of the file to save data to.
        - data: The data to save.
        '''
        with open(filename, 'w') as file:
            json.dump(data, file, indent=4)