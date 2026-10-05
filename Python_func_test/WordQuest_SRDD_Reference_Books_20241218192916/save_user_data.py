def save_user_data(user):
    '''
    Saves user data to a file.
    '''
    data = {'name': user.name, 'progress': user.progress}
    with open('user_data.json', 'w') as file:
        json.dump(data, file)