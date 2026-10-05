def load_preferences(self):
        '''
        Loads user preferences from a JSON file.
        '''
        try:
            with open(f'preferences.json', f'r') as file:
                self.preferences = json.load(file)
            print(f'User preferences loaded successfully.', flush=True, end=f'\n')
        except FileNotFoundError:
            print(f'No preferences found. Using default settings.', flush=True, end=f'\n')
        except json.JSONDecodeError:
            print(f'Error loading preferences. Invalid file format.', flush=True, end=f'\n')