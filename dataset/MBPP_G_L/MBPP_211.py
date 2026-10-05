def count_Num(n):
    count = 0
    for i in range(0, 2 ** (n + 1)):
        if i & 1 and i & 1 << n:
            count += 1
    return count