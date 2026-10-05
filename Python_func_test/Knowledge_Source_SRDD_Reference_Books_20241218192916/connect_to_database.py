def connect_to_database():
    connection = sqlite3.connect(f'resources.db')
    return connection