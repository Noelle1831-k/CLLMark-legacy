def last_Two_Digits(N):
    if N < 2:
        return 1
    last_two = 1
    for i in range(2, N + 1):
        last_two *= i
        last_two %= 100
    return last_two