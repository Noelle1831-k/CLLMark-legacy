def highest_Power_of_2(n):
    if n < 1:
        return 0
    highest_power = 1
    while highest_power <= n:
        highest_power *= 2
    return highest_power // 2