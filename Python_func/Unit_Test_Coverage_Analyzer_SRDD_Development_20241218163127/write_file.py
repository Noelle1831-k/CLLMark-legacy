def write_file(file_path, content):
    log_message(f"Writing to file: {file_path}")
    with open(file_path, 'w') as file:
        file.write(content)
    log_message(f"File written successfully: {file_path}")