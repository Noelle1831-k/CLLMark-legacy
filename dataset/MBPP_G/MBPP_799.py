def left_Rotate(n, d):
    return n << d | n >> 32 - d