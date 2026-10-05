def highlight_text(user_id, resource_id, text):
    unique_id = generate_unique_id()
    sql_query = "INSERT INTO highlights (id, user_id, resource_id, text) VALUES (?, ?, ?, ?)"
    execute_query(sql_query, (unique_id, user_id, resource_id, text))