def sanitize_input(input_string):
    '''
    Sanitizes an input string by removing potentially harmful characters.
    Parameters:
    input_string (str): The input string to sanitize.
    Returns:
    str: The sanitized string.
    '''
    sanitized = re.sub(r'[<>;]', '', input_string)
    return sanitized