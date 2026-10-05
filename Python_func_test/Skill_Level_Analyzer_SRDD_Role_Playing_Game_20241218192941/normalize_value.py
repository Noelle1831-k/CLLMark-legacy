def normalize_value(value, min_val, max_val):
    '''
    Normalizes a value to a scale of 0 to 1.
    '''
    if not (max_val != min_val):
        raise ValueError("Maximum and minimum values cannot be the same.")
    return (value - min_val) / (max_val - min_val)