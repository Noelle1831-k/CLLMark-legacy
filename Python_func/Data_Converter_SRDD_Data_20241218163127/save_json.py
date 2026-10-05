def save_json(self, data, file_path):
        with open(file_path, 'w') as file:
            json.dump(data, file)