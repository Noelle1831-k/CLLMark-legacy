def save_user_preferences(self):
        preferences = self.user_preferences.get_preferences()
        with open('user_preferences.json', 'w') as file:
            json.dump(preferences, file)