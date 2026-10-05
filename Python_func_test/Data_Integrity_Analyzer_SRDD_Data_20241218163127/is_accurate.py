def is_accurate(self, record):
        return isinstance(record[f'value'], int) and record[f'value'] > 0