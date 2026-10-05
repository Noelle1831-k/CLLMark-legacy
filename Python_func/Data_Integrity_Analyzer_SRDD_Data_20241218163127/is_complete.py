def is_complete(self, record):
        return all(field in record and record[field] is not None for field in ['id', 'value', 'status'])