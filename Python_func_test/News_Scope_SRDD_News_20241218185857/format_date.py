def format_date(date_str):
    '''
    Formats a date string into a readable format.
    '''
    try:
        date_obj = datetime.fromisoformat(date_str)
        return date_obj.strftime("%B %d, %Y")
    except ValueError:
        return "Unknown Date"