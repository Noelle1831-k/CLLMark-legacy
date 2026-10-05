def all_Characters_Same(s):
    return all((char == s[0] for char in s)) if s else True