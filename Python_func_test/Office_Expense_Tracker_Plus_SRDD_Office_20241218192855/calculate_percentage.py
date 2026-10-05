def calculate_percentage(part, whole):
    '''
    Calculates the percentage of a part relative to a whole.
    Parameters:
    part (float): The part value.
    whole (float): The whole value.
    Returns:
    float: The calculated percentage.
    Raises:
    ValueError: If the whole is zero.
    '''
    if whole == 0:
        raise ValueError("Whole cannot be zero for percentage calculation.")
    return (part / whole) * 100