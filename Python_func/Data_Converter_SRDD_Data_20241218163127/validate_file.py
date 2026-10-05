def validate_file(self, file_path):
        '''
        Validates the file path to ensure it exists and is of a supported format.
        '''
        if not os.path.exists(file_path):
            self.log(f"File not found: {file_path}")
            raise FileNotFoundError(f"File not found: {file_path}")
        valid_extensions = ['.csv', '.xlsx', '.json', '.xml']
        if not any(file_path.endswith(ext) for ext in valid_extensions):
            self.log(f"Unsupported file format: {file_path}")
            raise ValueError(f"Unsupported file format: {file_path}")
        self.log(f"File validated successfully: {file_path}")