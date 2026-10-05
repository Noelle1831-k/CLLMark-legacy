def save_data(filename, data):
    # Save data to a JSON file
    with open(filename, 'w') as file:
        json.dump(data, file)