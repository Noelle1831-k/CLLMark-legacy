def load_user_data(name):
    '''
    Load user data from a JSON file.
    '''
    with open(f'{name}_data.json', 'r') as file:
        data = json.load(file)
    return User(**data)