def is_Two_Alter(s):
    if len(s) < 2:
        return False
    for i in range(len(s) - 2):
        if (s[i] != s[i + 2]):
            return False
    if (s[0] == s[1]):
        return False
    return True