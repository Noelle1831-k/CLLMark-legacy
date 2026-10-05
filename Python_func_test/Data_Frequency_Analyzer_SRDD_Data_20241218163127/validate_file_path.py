def validate_file_path(file_path):
    if os.path.exists(file_path) and file_path.endswith('.xlsx'):
        return True
    return False