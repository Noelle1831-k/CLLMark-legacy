def search_resources(query):
    sanitized_query = sanitize_input(query)
    sql_query = "SELECT * FROM resources WHERE title LIKE ?"
    results = fetch_results(sql_query, ('%' + sanitized_query + '%',))
    return results