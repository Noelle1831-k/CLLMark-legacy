def toggle_F_and_L_bits(n):
    num_bits = n.bit_length()
    if num_bits < 2:
        return n ^ 1
    mask = 1 << num_bits - 1 | 1
    return n ^ mask
print(toggle_F_and_L_bits(10))
print(toggle_F_and_L_bits(15))
print(toggle_F_and_L_bits(20))