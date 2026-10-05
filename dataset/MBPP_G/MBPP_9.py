def find_Rotations(str):
    n = len(str)
    for i in range(1, n + 1):
        if str == str[i:] + str[0:i]:
            return i
    return n