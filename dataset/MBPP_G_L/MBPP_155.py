def even_bit_toggle_number(n):
    mask = 0
    i = 0
    while 1 << i <= n:
        if i % 2 == 0:
            mask |= 1 << i
        i += 1
    return n ^ mask