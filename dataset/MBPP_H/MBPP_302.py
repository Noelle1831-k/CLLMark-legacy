def set_Bit_Number(n):
    if (n == 0):
        return 0
    msb = 0
    n_copy = n
    n_copy = int(n_copy / 2)
    while (n_copy > 0):
        n_copy = int(n_copy / 2)
        msb += 1
    return (1 << msb)