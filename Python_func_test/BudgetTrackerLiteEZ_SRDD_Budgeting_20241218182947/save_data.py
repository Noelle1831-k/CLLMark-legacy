def save_data(self, data):
        '''
        Saves budget data to a file.
        Ensures data is formatted and saved with proper indentation for readability.
        '''
        try:
            with open(self.FILE_NAME, 'w') as file:
                json.dump(data, file, indent=4)
            print(f"Data saved to {self.FILE_NAME}.")
        except Exception as e:
            print(f"Error saving data: {e}")