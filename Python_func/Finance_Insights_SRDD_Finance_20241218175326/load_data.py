def load_data():
    '''
    Load initial data from a JSON file.
    '''
    try:
        with open('data.json', 'r') as file:
            data = json.load(file)
        return data
    except FileNotFoundError:
        return {}