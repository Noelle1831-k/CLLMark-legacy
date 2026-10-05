def load_user_preferences(self):
        try:
            with open('user_preferences.json', 'r') as file:
                preferences = json.load(file)
                self.user_preferences.set_preferences(preferences)
        except FileNotFoundError:
            print("User preferences file not found. Using default preferences.")