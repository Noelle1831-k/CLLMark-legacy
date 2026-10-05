def save_data(filename, data):
    '''
    Saves user data to a JSON file.
    '''
    try:
        with open(filename, 'w') as file:
            json.dump(data, file, indent=4)
    except IOError as e:
        print(f"Error: Unable to save data to {filename}. {e}")