def save_data(self, data):
        '''
        Save user data to a file.
        '''
        with open(self.filename, 'w') as file:
            json.dump(data, file)