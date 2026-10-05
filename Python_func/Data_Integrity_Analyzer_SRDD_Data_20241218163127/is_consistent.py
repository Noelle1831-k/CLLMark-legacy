def is_consistent(self, record):
        return record['status'] in ['valid', 'invalid']