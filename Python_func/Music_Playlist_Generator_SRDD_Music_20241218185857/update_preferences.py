def update_preferences(self, new_preferences):
        '''
        Updates the user preferences with new values and saves them.
        '''
        self.preferences.update(new_preferences)
        self.save_preferences()