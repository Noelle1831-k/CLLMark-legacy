def fetch_results(query, params=()):
    connection = connect_to_database()
    cursor = connection.cursor()
    cursor.execute(query, params)
    results = cursor.fetchall()
    connection.close()
    return results