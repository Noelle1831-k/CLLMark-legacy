def lucky_num(n):
    numbers = list(range(1, 100))
    i = 1
    while i < len(numbers):
        del numbers[numbers[i] - 1::numbers[i]]
        i += 1
    return numbers[0:n]