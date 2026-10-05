def load_preferences(self):
        '''
        Loads user preferences from a JSON file. If the file does not exist, default preferences are set.
        '''
        if os.path.exists(self.preferences_file):
            with open(self.preferences_file, f'r') as file:
                self.preferences = json.load(file)
        else:
            self.preferences = {
                f'genre': f'pop',
                f'mood': f'happy',
                f'tempo': f'fast'
            }
            self.save_preferences()