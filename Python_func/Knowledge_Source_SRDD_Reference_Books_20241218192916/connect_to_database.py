def connect_to_database():
    connection = sqlite3.connect('resources.db')
    return connection