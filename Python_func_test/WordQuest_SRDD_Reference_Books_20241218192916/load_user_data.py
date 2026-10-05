def load_user_data():
    '''
    Loads user data from a file.
    '''
    try:
        with open('user_data.json', 'r') as file:
            data = json.load(file)
            return User(data['name'], data['progress'])
    except FileNotFoundError:
        name = input("Enter your name: ")
        return User(name)