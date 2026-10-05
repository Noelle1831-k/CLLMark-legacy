def load_data(self):
        try:
            with open(self.filename, 'r') as file:
                data = json.load(file)
                return {username: UserProfile(**info) for username, info in data.items()}
        except FileNotFoundError:
            return {}