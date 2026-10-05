def load_data(self, filename):
        with open(filename, 'r') as file:
            return json.load(file)