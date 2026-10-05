def update_setting(self, key, value):
        '''
        Update a specific setting.
        '''
        settings = self.load_settings()
        settings[key] = value
        self.save_settings(settings)