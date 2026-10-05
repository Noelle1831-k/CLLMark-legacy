def load_preferences(self):
        try:
            with open('preferences.json', 'r') as file:
                self.preferences = json.load(file)
        except FileNotFoundError:
            self.preferences = {"categories": ["technology", "sports"], "sources": ["source1", "source2"]}
            self.save_preferences()