def save_data(data):
    '''
    Save data to a JSON file.
    '''
    with open('data.json', 'w') as file:
        json.dump(data, file)