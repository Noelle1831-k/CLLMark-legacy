def customize_preferences(self, custom_manager):
        '''
        Allows the user to customize their news preferences.
        '''
        print("Customizing user preferences...")
        custom_manager.set_preferences()
        print("Preferences have been updated.")