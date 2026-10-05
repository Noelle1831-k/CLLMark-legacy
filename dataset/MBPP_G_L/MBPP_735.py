def toggle_middle_bits(n):
    if n == 0:
        return 0
    num_bits = n.bit_length()
    if num_bits <= 2:
        return n
    middle_mask = (1 << num_bits - 1) - 1 >> 1
    toggle_mask = middle_mask << 1
    return n ^ toggle_mask