def load_data(filename):
    # Load data from a JSON file
    try:
        with open(filename, 'r') as file:
            return json.load(file)
    except FileNotFoundError:
        return {}