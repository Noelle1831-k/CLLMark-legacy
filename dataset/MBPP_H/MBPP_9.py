def find_Rotations(s):
    tmp = s + s
    n = len(s)
    for i in range(1, n + 1):
        substring = tmp[i: i + n]
        if (s == substring):
            return i
    return 0