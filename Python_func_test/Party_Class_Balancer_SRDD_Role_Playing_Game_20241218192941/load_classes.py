def load_classes(file_path="data.json"):
    '''
    Loads character classes and their abilities from a JSON file.
    '''
    try:
        with open(file_path, 'r') as file:
            data = json.load(file)
        return data
    except FileNotFoundError:
        print("Error: Data file not found.")
        return {}
    except json.JSONDecodeError:
        print("Error: Invalid JSON format.")
        return {}