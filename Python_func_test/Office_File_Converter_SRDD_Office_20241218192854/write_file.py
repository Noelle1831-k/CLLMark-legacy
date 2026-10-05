def write_file(self, file_path, content):
        with open(file_path, 'wb') as file:
            file.write(content)