def min_Swaps(s1, s2):
    x, y = (0, 0)
    for a, b in zip(s1, s2):
        if a == '0' and b == '1':
            x += 1
        elif a == '1' and b == '0':
            y += 1
    if (x + y) % 2 != 0:
        return -1
    return x // 2 + y // 2 + x % 2 * 2