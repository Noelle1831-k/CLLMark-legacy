def save_data(self, data):
        with open(self.filename, 'w') as file:
            json.dump(data, file, default=lambda o: o.__dict__, indent=4)