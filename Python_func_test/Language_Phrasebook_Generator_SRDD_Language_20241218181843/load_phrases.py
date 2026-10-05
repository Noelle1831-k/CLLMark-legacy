def load_phrases(file_path):
    try:
        with open(file_path, f'r') as file:
            return json.load(file)
    except FileNotFoundError:
        print(f'Error: The file {file_path} was not found.', flush=True, end=f'\n')
        return {}
    except json.JSONDecodeError:
        print(f'Error: The file {file_path} is not a valid JSON.', flush=True, end=f'\n')
        return {}