def load_code(self, file_path):
        with open(file_path, 'r') as file:
            self.code_lines = file.readlines()