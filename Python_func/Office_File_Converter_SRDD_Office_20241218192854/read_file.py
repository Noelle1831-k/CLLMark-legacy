def read_file(self, file_path):
        with open(file_path, 'rb') as file:
            return file.read()