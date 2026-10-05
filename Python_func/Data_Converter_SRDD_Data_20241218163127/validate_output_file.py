def validate_output_file(self, file_path):
        '''
        Validates the output file path to ensure it is of a supported format.
        '''
        valid_extensions = ['.csv', '.xlsx', '.json', '.xml']
        if not any(file_path.endswith(ext) for ext in valid_extensions):
            self.log(f"Unsupported output file format: {file_path}")
            raise ValueError(f"Unsupported output file format: {file_path}")
        self.log(f"Output file validated successfully: {file_path}")