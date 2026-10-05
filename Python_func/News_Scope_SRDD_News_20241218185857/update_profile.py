def update_profile(self, data):
        '''
        Updates the user's profile with new data.
        '''
        self.preferences.extend(data.get('preferences', []))