def initialize_app():
    db_connection = connect_to_database()
    return db_connection