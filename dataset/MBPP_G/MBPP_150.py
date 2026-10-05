def does_Contain_B(a, b, c):
    if c == 0:
        return a == b
    if (b - a) % c == 0 and (b - a) // c >= 0:
        return True
    return False