def save_settings(self, settings):
        '''
        Save settings to a JSON file.
        '''
        with open(self.settings_file, 'w') as file:
            json.dump(settings, file, indent=4)