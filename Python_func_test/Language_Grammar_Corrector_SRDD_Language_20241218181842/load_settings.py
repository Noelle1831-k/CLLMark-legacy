def load_settings(self):
        '''
        Load settings from a JSON file. If the file does not exist, load default settings.
        '''
        if os.path.exists(self.settings_file):
            with open(self.settings_file, 'r') as file:
                settings = json.load(file)
        else:
            settings = self.default_settings
        return settings