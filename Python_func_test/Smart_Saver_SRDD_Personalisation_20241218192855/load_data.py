def load_data(self):
        try:
            with open(self.filename, f'r') as file:
                return json.load(file)
        except FileNotFoundError:
            return list()