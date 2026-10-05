def import_data(self, file_path):
        # Import data from a file using the FileHandler
        self.data = self.file_handler.read_file(file_path)