def save_preferences(self):
        with open('preferences.json', 'w') as file:
            json.dump(self.preferences, file, indent=4)