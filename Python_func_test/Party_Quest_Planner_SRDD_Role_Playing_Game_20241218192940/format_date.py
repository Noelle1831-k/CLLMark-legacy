def format_date(date_string):
    '''
    Format a date string into a more readable format.
    '''
    from datetime import datetime
    try:
        date_object = datetime.strptime(date_string, '%Y-%m-%d')
        return date_object.strftime('%B %d, %Y')
    except ValueError:
        print("Invalid date format. Please use YYYY-MM-DD.")
        return None