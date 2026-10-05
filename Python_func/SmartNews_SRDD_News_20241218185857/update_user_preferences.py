def update_user_preferences(self, new_preferences):
        self.preferences.update(new_preferences)
        with open('user_preferences.json', 'w') as file:
            json.dump(self.preferences, file)