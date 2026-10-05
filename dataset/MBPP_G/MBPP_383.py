def even_bit_toggle_number(n):
    bit_length = n.bit_length()
    mask = 0
    for i in range(0, bit_length, 2):
        mask |= 1 << i
    return n ^ mask