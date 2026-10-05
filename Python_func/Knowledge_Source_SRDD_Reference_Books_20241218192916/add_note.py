def add_note(user_id, resource_id, note):
    unique_id = generate_unique_id()
    sql_query = "INSERT INTO notes (id, user_id, resource_id, note) VALUES (?, ?, ?, ?)"
    execute_query(sql_query, (unique_id, user_id, resource_id, note))