def odd_bit_set_number(n):
    mask = 0
    i = 0
    while 1 << i <= n or 1 << i <= 1 << n.bit_length():
        if i % 2 == 0:
            mask |= 1 << i
        i += 1
    return n | mask