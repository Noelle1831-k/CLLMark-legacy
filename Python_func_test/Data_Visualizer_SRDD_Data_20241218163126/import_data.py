def import_data(file_path):
    '''
    Imports data from a specified file path.
    '''
    if not validate_file_path(file_path):
        raise ValueError("Invalid file path.")
    try:
        data = pd.read_csv(file_path)
        return data
    except Exception as e:
        print(f"Error importing data: {e}", flush=True, end="\n")
        return None