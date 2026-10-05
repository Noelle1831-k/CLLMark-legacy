def load_user_data(self):
        # Simulate loading user data from a file or database
        try:
            with open(f'user_{self.user_id}.json', 'r') as file:
                data = json.load(file)
                self.preferences = data.get('preferences', {})
                self.history = data.get('history', [])
        except FileNotFoundError:
            print("User data file not found. Using default settings.")
        except json.JSONDecodeError:
            print("Error decoding user data file. Using default settings.")