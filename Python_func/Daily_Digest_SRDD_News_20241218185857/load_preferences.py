def load_preferences(self):
        try:
            with open("preferences.json", "r") as file:
                self.preferences = json.load(file)
        except FileNotFoundError:
            utils.log_activity("Preferences file not found. Loading default preferences.")
            self.preferences = {"categories": ["general", "technology"]}