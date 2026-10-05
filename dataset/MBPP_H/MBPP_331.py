def count_unset_bits(n):
    count = 0
    x = 1
    while (x <= n):
        if ((x & n) == 0):
            count += 1
        x = x << 1
    return count