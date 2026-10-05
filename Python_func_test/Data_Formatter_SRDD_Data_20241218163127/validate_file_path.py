def validate_file_path(file_path):
        # Validate if the file path exists
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"The file {file_path} does not exist.")
        return True