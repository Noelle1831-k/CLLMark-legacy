def save_to_file(self, filename, data):
        '''
        Save data to a file in JSON format.
        '''
        try:
            with open(filename, 'w') as file:
                json.dump(data, file, indent=4)
        except IOError as e:
            print(f"An error occurred while saving to file: {e}")