def hamming_Distance(n1, n2):
    x = int(n1) ^ int(n2)
    setBits = 0
    while (x > 0):
        setBits += x & 1
        x >>= 1
    return setBits