def execute_query(query, params=()):
    connection = connect_to_database()
    cursor = connection.cursor()
    cursor.execute(query, params)
    connection.commit()
    connection.close()