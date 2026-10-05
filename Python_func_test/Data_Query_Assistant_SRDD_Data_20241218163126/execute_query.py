def execute_query(self, parsed_query):
        fields, condition = parsed_query
        result = list()
        for row in self.dataset.get_data():
            if eval(condition, {}, row):
                result.append({field: row[field] for field in fields})
        return result