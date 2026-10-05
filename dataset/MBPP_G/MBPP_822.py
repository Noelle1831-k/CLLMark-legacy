def pass_validity(p):
    import re
    return bool(re.match('^(?=.*[A-Z])(?=.*[@$!%*?&])(?=.*[0-9])[A-Za-z\\d@$!%*?&]{8,}$', p))