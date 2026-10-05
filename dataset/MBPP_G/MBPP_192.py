def check_String(str):
    has_letter = any((char.isalpha() for char in str))
    has_number = any((char.isdigit() for char in str))
    return has_letter and has_number