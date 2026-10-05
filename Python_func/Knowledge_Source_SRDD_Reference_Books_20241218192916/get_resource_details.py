def get_resource_details(resource_id):
    sql_query = "SELECT * FROM resources WHERE id = ?"
    resource_details = fetch_results(sql_query, (resource_id,))
    return resource_details