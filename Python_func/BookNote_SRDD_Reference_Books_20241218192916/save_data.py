def save_data(self, filename, data):
        with open(filename, 'w') as file:
            json.dump(data, file)