def load_data(self):
        with open(self.filename, 'r') as file:
            return json.load(file)