def all_Characters_Same(s):
    n = len(s)
    if n == 0:
        return True
    for i in range(1, n):
        if s[i] != s[0]:
            return False
    return True