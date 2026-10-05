def read_file(file_path):
    try:
        with open(file_path, f'r') as file:
            return file.read()
    except FileNotFoundError:
        print(f'File not found: {file_path}', flush=True, end=f'\n')
        return f''
    except IOError as e:
        print(f'Error reading file {file_path}: {e}', flush=True, end=f'\n')
        return f''