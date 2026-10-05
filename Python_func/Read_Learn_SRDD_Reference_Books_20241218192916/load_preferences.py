def load_preferences(self):
        '''
        Loads user preferences from a JSON file.
        '''
        try:
            with open("preferences.json", "r") as file:
                self.preferences = json.load(file)
            print("User preferences loaded successfully.")
        except FileNotFoundError:
            print("No preferences found. Using default settings.")
        except json.JSONDecodeError:
            print("Error loading preferences. Invalid file format.")