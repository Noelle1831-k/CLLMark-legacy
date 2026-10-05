def validate_email(email):
    '''
    Validates an email address using regex.
    Parameters:
    email (str): The email address to validate.
    Returns:
    bool: True if the email is valid, False otherwise.
    '''
    email_regex = r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)"
    if re.match(email_regex, email):
        return True
    return False