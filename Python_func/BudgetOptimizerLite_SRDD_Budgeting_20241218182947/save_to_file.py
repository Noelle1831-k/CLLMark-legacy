def save_to_file(self, data, filename):
        with open(filename, 'w') as file:
            json.dump(data, file)