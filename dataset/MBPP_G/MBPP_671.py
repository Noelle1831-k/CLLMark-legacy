def set_Right_most_Unset_Bit(n):
    return n if n & n + 1 == 0 else n | n + 1 & ~n