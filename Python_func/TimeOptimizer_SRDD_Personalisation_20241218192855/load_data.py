def load_data(self):
        # Load data from a JSON file
        try:
            with open('user_data.json', 'r') as f:
                data = json.load(f)
            print("Data has been loaded from user_data.json.")
            return data
        except FileNotFoundError:
            print("No previous data found.")
            return {}