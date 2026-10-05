def read_file(file_path):
    log_message(f"Reading file: {file_path}")
    with open(file_path, 'r') as file:
        content = file.read()
    log_message(f"File read successfully: {file_path}")
    return content