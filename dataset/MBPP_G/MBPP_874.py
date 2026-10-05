def check_Concat(str1, str2):
    if not str2:
        return False
    if len(str1) % len(str2) != 0:
        return False
    return str1 == str2 * (len(str1) // len(str2))