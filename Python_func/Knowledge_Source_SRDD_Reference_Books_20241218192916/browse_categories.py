def browse_categories():
    sql_query = "SELECT * FROM categories"
    categories = fetch_results(sql_query)
    return categories