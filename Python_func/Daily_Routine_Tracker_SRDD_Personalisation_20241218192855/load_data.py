def load_data(filename):
    '''
    Loads user data from a JSON file.
    '''
    try:
        with open(filename, 'r') as file:
            return json.load(file)
    except FileNotFoundError:
        print(f"Error: {filename} not found. Starting with an empty dataset.")
        return {}
    except json.JSONDecodeError:
        print("Error: Invalid JSON format in the data file. Starting with an empty dataset.")
        return {}