def parse_date(date_str):
    '''
    Parse a date string into a date object.
    '''
    from datetime import datetime
    return datetime.strptime(date_str, "%Y-%m-%d")