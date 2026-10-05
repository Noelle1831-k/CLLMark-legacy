def bookmark_resource(user_id, resource_id):
    unique_id = generate_unique_id()
    sql_query = "INSERT INTO bookmarks (id, user_id, resource_id) VALUES (?, ?, ?)"
    execute_query(sql_query, (unique_id, user_id, resource_id))