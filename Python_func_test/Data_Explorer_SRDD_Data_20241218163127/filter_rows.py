def filter_rows(self, data, criteria):
        # Filter rows based on specified criteria
        column, value = criteria['column'], criteria['value']
        return data.query(f"{column} {value}")