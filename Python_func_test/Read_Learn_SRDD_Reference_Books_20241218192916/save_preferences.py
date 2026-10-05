def save_preferences(self):
        '''
        Saves the current preferences to a JSON file.
        '''
        try:
            with open("preferences.json", "w") as file:
                json.dump(self.preferences, file, indent=4)
            print("Preferences saved successfully.")
        except Exception as e:
            print(f"Error saving preferences: {e}")