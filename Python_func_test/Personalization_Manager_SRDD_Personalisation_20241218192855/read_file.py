def read_file(self, file_path):
        with open(file_path, f'r') as file:
            return json.load(file)