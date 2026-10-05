def save_preferences(self):
        '''
        Saves the current user preferences to a JSON file.
        '''
        with open(self.preferences_file, 'w') as file:
            json.dump(self.preferences, file, indent=4)