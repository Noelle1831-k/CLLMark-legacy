def load_preferences(self):
        '''
        Loads user preferences from a JSON file. If the file does not exist, default preferences are set.
        '''
        if os.path.exists(self.preferences_file):
            with open(self.preferences_file, 'r') as file:
                self.preferences = json.load(file)
        else:
            self.preferences = {
                "genre": "pop",
                "mood": "happy",
                "tempo": "fast"
            }
            self.save_preferences()