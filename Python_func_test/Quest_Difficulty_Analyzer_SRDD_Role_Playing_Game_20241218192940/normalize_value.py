def normalize_value(value, min_value, max_value):
    '''
    Normalize a value to a scale of 0 to 1 based on its minimum and maximum possible values.
    '''
    return (value - min_value) / (max_value - min_value)