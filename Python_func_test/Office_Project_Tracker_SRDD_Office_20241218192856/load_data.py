def load_data(self):
        try:
            with open(self.file_path, 'r') as file:
                data = json.load(file)
                print("Data loaded successfully.")
                return data
        except FileNotFoundError:
            print("No previous data found. Starting fresh.")
            return {'projects': list(), 'tasks': list(), 'users': list()}