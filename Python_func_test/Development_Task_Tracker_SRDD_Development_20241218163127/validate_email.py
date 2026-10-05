def validate_email(email):
    '''
    Validates an email address using a regular expression.
    '''
    pattern = r'[^@]+@[^@]+\.[^@]+'
    return re.match(pattern, email) is not None