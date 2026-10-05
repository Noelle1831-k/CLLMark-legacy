def count_Unset_Bits(n):
    total_bits = 0
    unset_bits = 0
    for i in range(n + 1):
        total_bits += len(bin(i)) - 2
        unset_bits += len(bin(i)) - 2 - bin(i).count('1')
    return unset_bits