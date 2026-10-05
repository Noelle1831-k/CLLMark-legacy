def is_accurate(self, record):
        return isinstance(record['value'], int) and record['value'] > 0