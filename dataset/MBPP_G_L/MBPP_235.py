def even_bit_set_number(n):
    even_bit_set = 0
    i = 0
    while 1 << i <= n:
        if i % 2 == 0:
            even_bit_set |= 1 << i
        i += 1
    return n | even_bit_set