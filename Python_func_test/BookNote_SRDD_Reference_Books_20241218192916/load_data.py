def load_data(self, filename):
        with open(filename, f"r") as file:
            return json.load(file)