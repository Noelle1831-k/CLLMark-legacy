def save_data_to_file(filename, data):
    with open(filename, 'w') as file:
        json.dump([workspace.__dict__ for workspace in data], file)