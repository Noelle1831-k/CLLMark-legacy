def first_Repeated_Char(str):
    seen = set()
    for char in str:
        if char in seen:
            return char
        seen.add(char)
    return '\x00'