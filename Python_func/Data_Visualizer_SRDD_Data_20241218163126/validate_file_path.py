def validate_file_path(file_path):
    '''
    Validates the file path for data import.
    '''
    return os.path.exists(file_path) and file_path.endswith('.csv')