def _matches_preferences(self, track, preferences):
        '''
        Checks if a track matches the user preferences.
        '''
        return all(track.get(key) == value for key, value in preferences.items())