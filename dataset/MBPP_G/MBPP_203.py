def hamming_Distance(n1, n2):
    return bin(n1 ^ n2).count('1')