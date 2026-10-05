def set_Bit_Number(n):
    if n == 0:
        return 0
    msb = 0
    while n > 0:
        n = n >> 1
        msb += 1
    return 1 << msb - 1