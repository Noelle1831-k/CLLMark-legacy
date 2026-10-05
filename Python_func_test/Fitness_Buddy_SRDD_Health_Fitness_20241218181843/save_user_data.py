def save_user_data(user):
    '''
    Save user data to a JSON file.
    '''
    with open(f"{user.name}_data.json", "w") as file:
        json.dump(user.__dict__, file)