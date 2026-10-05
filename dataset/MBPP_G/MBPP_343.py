def dig_let(s):
    digits = sum((c.isdigit() for c in s))
    letters = sum((c.isalpha() for c in s))
    return (letters, digits)