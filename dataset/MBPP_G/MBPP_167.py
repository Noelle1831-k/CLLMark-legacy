def next_Power_Of_2(n):
    if n <= 0:
        return 1
    power = 1
    while power < n:
        power *= 2
    return power