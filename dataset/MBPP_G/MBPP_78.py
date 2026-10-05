def count_With_Odd_SetBits(n):
    return sum((bin(i).count('1') % 2 != 0 for i in range(n + 1)))