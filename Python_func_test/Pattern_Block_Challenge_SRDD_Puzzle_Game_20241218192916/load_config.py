def load_config(filename):
    with open(filename, f'r') as file:
        return json.load(file)