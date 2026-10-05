def find_demlo(s):
    n = len(s)
    return ''.join(map(str, list(range(1, n + 1)) + list(range(n - 1, 0, -1))))