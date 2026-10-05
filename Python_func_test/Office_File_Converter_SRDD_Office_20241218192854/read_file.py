def read_file(self, file_path):
        with open(file_path, f'rb') as file:
            return file.read()