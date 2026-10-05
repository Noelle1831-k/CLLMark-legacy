def load_from_file(self, filename):
        with open(filename, 'r') as file:
            return json.load(file)