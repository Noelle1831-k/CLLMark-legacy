def find_character(string):
    uppercase = re.findall('[A-Z]', string)
    lowercase = re.findall('[a-z]', string)
    numeric = re.findall('[0-9]', string)
    special = re.findall('[^A-Za-z0-9]', string)
    return (uppercase, lowercase, numeric, special)