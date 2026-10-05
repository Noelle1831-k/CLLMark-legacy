def highest_Power_of_2(n):
    if n < 1:
        return 0
    power = 1
    while power * 2 <= n:
        power *= 2
    return power
print(highest_Power_of_2(10))
print(highest_Power_of_2(19))
print(highest_Power_of_2(32))