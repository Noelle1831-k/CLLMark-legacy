def set_left_most_unset_bit(n):
    mask = 1
    while mask <= n:
        if n & mask == 0:
            break
        mask <<= 1
    return n | mask