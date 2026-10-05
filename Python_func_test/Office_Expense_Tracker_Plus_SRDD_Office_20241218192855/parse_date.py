def parse_date(date_string):
    '''
    Parses a date string into a date object.
    Parameters:
    date_string (str): The date string to parse.
    Returns:
    datetime: The parsed date object.
    Raises:
    ValueError: If the date string is not in a recognized format.
    '''
    date_formats = ["%Y-%m-%d", "%d/%m/%Y", "%m-%d-%Y"]
    for fmt in date_formats:
        try:
            return datetime.strptime(date_string, fmt)
        except ValueError:
            continue
    raise ValueError("Date string '{}' is not in a recognized format.".format(date_string))