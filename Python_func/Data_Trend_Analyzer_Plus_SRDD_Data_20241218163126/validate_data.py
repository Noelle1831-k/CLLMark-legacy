def validate_data(data):
    '''
    Validate data sets.
    '''
    if data is not None and not data.empty:
        return True
    return False