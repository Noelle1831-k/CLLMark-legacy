def save_data(self, data):
        with open(self.filename, 'w') as file:
            json.dump(data, file, indent=4)