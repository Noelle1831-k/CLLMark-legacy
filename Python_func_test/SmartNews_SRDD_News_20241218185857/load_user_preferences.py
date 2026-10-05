def load_user_preferences(self):
        # Simulate loading user preferences from a JSON file
        try:
            with open('user_preferences.json', 'r') as file:
                self.preferences = json.load(file)
        except FileNotFoundError:
            self.preferences = {"categories": ["technology", "science"], "keywords": ["AI", "machine learning"]}