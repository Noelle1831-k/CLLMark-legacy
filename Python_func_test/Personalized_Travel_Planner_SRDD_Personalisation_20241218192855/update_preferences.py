def update_preferences(self, new_prefs):
        '''
        Updates user preferences with the given dictionary of new preferences.
        Args:
            new_prefs (dict): A dictionary with preference categories as keys
                              and interest levels as values.
        '''
        for key, value in new_prefs.items():
            if 0 <= value <= 5:  # Validate preference levels
                self.preferences[key] = value
            else:
                print(f'Invalid preference level for {key}. Must be between 0 and 5.', flush=True, end='\n')